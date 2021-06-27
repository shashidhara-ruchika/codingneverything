"""
python RatingCounter.py u.data
"""

from mrjob.job import MRJob


# Count of the total ratings given for each rating
class MRRatingCounter(MRJob):

    def mapper(self, key, line:str) -> (str, int):
        (userID, movieID, rating, timestamp) = line.split('\t')
        yield rating, 1

    def reducer(self, rating:str, occurences:tuple) -> (str, int):
        yield rating, sum(occurences)


if __name__ == '__main__':
    MRRatingCounter.run()
