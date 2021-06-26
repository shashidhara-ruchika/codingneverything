"""
python SortedSpentAmountCustomer_withCombiner.py
"""

from mrjob.job import MRJob
from mrjob.job import MRStep


# Find total amount spent by each customer
class MRSortedSpentAmountCustomer_withCombiner(MRJob):

    def steps(self):
        return [
                MRStep(
                        mapper   = self.mapper_get_order_amounts,
                        combiner = self.reducer_get_total_amounts,
                        reducer  = self.reducer_get_total_amounts
                        ),
                MRStep(
                        mapper   = self.mapper_make_amount_as_key,
                        reducer  = self.reducer_get_sorted_amounts
                        )
                ]

    # MR Job 1

    def mapper_get_order_amounts(self, key, line : str) -> (str, float):
        customer_id, item_id, order_amount = line.split(',')
        yield customer_id, float(order_amount)

    def reducer_get_total_amounts(self, customer_id : str, order_amount : tuple) -> (str, float):
        yield customer_id, sum(order_amount)

    # MR Job 2

    def mapper_make_amount_as_key(self, customer_id : str, total_amount : str) -> (str, str):
        yield '%04.02f'%float(total_amount), customer_id

    def reducer_get_sorted_amounts(self, total_amount : str, customer_id : tuple) -> (float, str):
        for c_id in customer_id:
            yield c_id, float(total_amount)


if __name__ == "__main__":
    MRSortedSpentAmountCustomer_withCombiner.run()
