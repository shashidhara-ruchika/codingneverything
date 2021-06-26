"""
python AvgAgeByFriendCount.py fakefriends.csv
"""

from mrjob.job import MRJob


# Average age of friends grouped by number of friends
class MRAvgAgeByFriendCount(MRJob):

    def mapper(self, key, line:str) -> (str, float):
        (userID, name, age, no_of_friends) = line.split(',')
        yield age, float(no_of_friends)

    def reducer(self, age:str, no_of_friends:tuple) -> (str, float):
        sum_friends = 0
        count_friends = 0
        for friend_count in no_of_friends:
            sum_friends += friend_count
            count_friends += 1
        yield age, '%.03f'%float(sum_friends/count_friends)  # format upto 3 decimal places


if __name__ == '__main__':
    MRAvgAgeByFriendCount.run()
