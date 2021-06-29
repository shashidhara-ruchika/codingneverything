"""
python MostRatedMovie_withCombiner.py u.data
"""

from mrjob.job import MRJob
from mrjob.job import MRStep


# Obtain the most rated movie
class MRMostRatedMovie_withCombiner(MRJob):

    def steps(self):
        return [
                MRStep(
                        mapper   = self.mapper_get_movie_rating_counts,
                        combiner = self.combiner_get_total_movie_rating_counts,
                        reducer  = self.reducer_get_total_movie_rating_counts
                        ),
                MRStep(
                        reducer  = self.reducer_get_max_rated_movie
                        )
                ]

    # MR Job 1

    def mapper_get_movie_rating_counts(self, key, line:str) -> (str, int):
        (userID, movieID, rating, timestamp) = line.split('\t')
        yield movieID, 1

    def combiner_get_total_movie_rating_counts(self, movieID:str, movie_rating_counts) -> (str, int):
        yield movieID, sum(movie_rating_counts)

    def reducer_get_total_movie_rating_counts(self, movieID:str, movie_rating_counts:tuple) -> (None, (str, int)):
        yield None, (sum(movie_rating_counts), movieID)

    # MR Job 2

    def reducer_get_max_rated_movie(self, key:None, movie_rating_counts:tuple) -> (str, int):
        yield max(movie_rating_counts)


if __name__ == '__main__':
    MRMostRatedMovie_withCombiner.run()


"""
MR Job 1

The mapper extracts the movieID as key & 1 as value
indicating that the movie has been rated once.

The combiner combines the sum of movie ratings for a movieID amd outputs the
movieID as key and the movie ratings count as value

Next the group & sort phase from MapReduce runs and
that bunches together all of the ones from every
time that each movie idea was viewed.

The reducer in this does not do much for the key at all (key is None),
it just outputs the value which includes a tuple of
total number of times the movie has been rated & its movieID.


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
"""
