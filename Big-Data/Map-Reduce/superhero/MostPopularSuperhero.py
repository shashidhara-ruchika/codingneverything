"""
python MostPopularSuperhero.py --names=Marvel_Names Marvel_Graph
"""

from mrjob.job import MRJob
from mrjob.job import MRStep


class MRMostPopularSuperhero(MRJob):

    def configure_args(self):
        super(MRMostPopularSuperhero, self).configure_args()
        self.add_file_arg('--names', help='Path to Marvel_Names.txt')

    def steps(self):
        return [
                MRStep(
                        mapper      = self.mapper_friend_count_per_line,
                        reducer     = self.reducer_get_total_friend_count
                        ),
                MRStep(
                        mapper_init = self.mapper_init_load_name_hashtable,
                        mapper      = self.mapper_prep_sort,
                        reducer     = self.reducer_hero_with_most_friends
                        )
                ]

    # MR Job 1

    def mapper_friend_count_per_line(self, key:str, line:str) -> (int, int):
        fields = line.split()
        hero_id = fields[0]
        num_friends = len(fields) - 1
        yield int(hero_id), int(num_friends)

    def reducer_get_total_friend_count(self, hero_id:int, num_friends:tuple) -> (int, int):
        yield int(hero_id), sum(num_friends)

    # MR Job 2

    def mapper_init_load_name_hashtable(self):
        self.hero_names = dict()
        with open("Marvel_Names", encoding="ascii", errors="ignore") as f:
            for line in f:
                fields = line.split('"')
                hero_id = int(fields[0])
                hero_name = fields[1]
                self.hero_names[hero_id] = hero_name

    def mapper_prep_sort(self, hero_id:int, friend_count:int) -> (None, (int, str)):
        yield None, (int(friend_count), self.hero_names[hero_id])

    def reducer_hero_with_most_friends(self, key:None, friend_count_tuple:(int, str)) -> (int, str):
        yield max(friend_count_tuple)


if __name__ == "__main__":
    MRMostPopularSuperhero.run()
