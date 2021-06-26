"""
python AvgAgeByFriendCount2.py fakefriends.csv
"""

from mrjob.job import MRJob
from json import dumps, loads


# Average age of friends grouped by number of friends
class MRAvgAgeByFriendCount2(MRJob):

    def mapper(self, key, line:str) -> (str, float):
        (userID, name, age, no_of_friends) = line.split(',')
        # for map value dump a dictionary with no_of_friends as key & 1 as value
        yield age, dumps({no_of_friends : 1}, skipkeys = True)

    def reducer(self, age:str, no_of_friends:tuple) -> (str, float):
        sum_friends = 0
        count_friends = 0
        # no_of_friends contains a tuple of jsons in a string
        for friend_count_json_str in no_of_friends:
            # convert each json in string into a dictionary
            json_obj = loads(friend_count_json_str)
            # json_obj_key is str that holds the first element's key
            # (it is the only element in this json, hence no need to traverse in a for loop)
            json_obj_key = next(iter(json_obj))
            sum_friends += int(json_obj_key)
            count_friends += json_obj[json_obj_key]
        yield age, '%.03f'%float(sum_friends/count_friends)  # format upto 3 decimal places


if __name__ == "__main__":
    MRAvgAgeByFriendCount2.run()
