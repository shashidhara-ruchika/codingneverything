"""
python MostRatedMovie_withCombiner_withMovieName.py --items=u.ITEM u.data
"""

from mrjob.job import MRJob
from mrjob.job import MRStep


# Obtain the most rated movie
class MRMostRatedMovie_withCombiner_withMovieName(MRJob):

    # configure_args tell MRJob that we have additional options that we want to
    # accept on the command line when we run this script.
    def configure_args(self):
        super(MRMostRatedMovie_withCombiner_withMovieName, self).configure_args()
        self.add_file_arg('--items', help='Path to u.item')
        # Here we are indicating thaat there is another ancillary file that
        # we need to send along with everything ele in our MR Job
        # after .--items the file will be distributed along with the code for
        # the script to every node that this job might run on.
        # This is how we make sure that ancillary data like her database of
        # movie IDs to movie names gets passed along to every node of the job where it's needed.

    def steps(self):
        return [
                MRStep(
                        mapper       = self.mapper_get_movie_rating_counts,
                        combiner     = self.combiner_get_total_movie_rating_counts,
                        reducer_init = self.reducer_init_get_total_movie_rating_counts(),
                        reducer      = self.reducer_get_total_movie_rating_counts
                        ),
                MRStep(
                        reducer      = self.reducer_get_max_rated_movie
                        )
                ]

    # MR Job 1

    def mapper_get_movie_rating_counts(self, key, line:str) -> (str, int):
        (userID, movieID, rating, timestamp) = line.split('\t')
        yield movieID, 1

    def combiner_get_total_movie_rating_counts(self, movieID:str, movie_rating_counts) -> (str, int):
        yield movieID, sum(movie_rating_counts)

    def reducer_init_get_total_movie_rating_counts(self):
        # Build a Hash Table for lookup
        # key: movieID, value: movie_name
        self.movie_names = dict()
        # open u.item file to read the contents
        with open("u.ITEM", encoding='ascii', errors='ignore') as f:
            for line in f:
                fields = line.split('|')
                # The first field is the movieID, second field is the movie_name
                self.movie_names[fields[0]] = fields[1]

    def reducer_get_total_movie_rating_counts(self, movieID:str, movie_rating_counts:tuple) -> (None, (str, int)):
        yield None, (sum(movie_rating_counts), self.movie_names[movieID])

    # MR Job 2

    def reducer_get_max_rated_movie(self, key:None, movie_rating_counts:tuple) -> (str, int):
        yield max(movie_rating_counts)


if __name__ == '__main__':
    MRMostRatedMovie_withCombiner_withMovieName.run()


"""

MR Job 1

The mapper extracts the movieID as key & 1 as value
indicating that the movie has been rated once.

The combiner combines the sum of movie ratings for a movieID amd outputs the
movieID as key and the movie ratings count as value

Next the group & sort phase from MapReduce runs and
that bunches together all of the ones from every
time that each movie idea was viewed.

The reducer_init function runs before the reducer function here

The reducer in this does not do much for the key at all (key is None),
it just outputs the value which includes a tuple of
total number of times the movie has been rated & its movie_namewhich is obtained from
the look up from the movie names hash table using the movieID.


MR Job 2

There is no mapper in this phase.

This job recieves None as its key,
hence all pair will accumulate in one list for the reducer

The reducer sorts (sort based on the first element in the tuple - movie rating counts)
the values and find the maximum view count out of all of them
& outputs the maximum rated movieID & the number of times it has been rated, which here is the maximum.

Exaplanations:

We want to use a second MR Job, since we need to find the global maximum
of all the ratings from all the reducers movie rating counts.

Basically our first reducer is trying to arrange the values such that they can,
Then we can run the max function on them in the second reducer
and that will run the max function on that
first field of the values which indicates the rating count.


ml-100k-u.item is a pipe '|' separated file

We just can't run MR on Hadoop to get the movieID & number of times it has been rated
and then look up the file in u.item, since each MR Job is performed on different nodes.

Hence, we have to make sure that u.item which is the file that contains the movie names
is actually distributed to every node that were running our job on &
 it's available to every node that's running on.

So, to do that we need to tell MapReduce and Hadoop potentially where u.item
is one of our input files using configure args & add file args
to make sure that this file is sent along with the code
for our MapReduce script to every node.
"""
