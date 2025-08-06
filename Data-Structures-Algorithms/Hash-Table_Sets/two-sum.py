# https://leetcode.com/problems/two-sum/description/

# https://neetcode.io/problems/two-integer-sum?list=neetcode150

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        count_freq = dict()

        for i, n in enumerate(nums):
            curr_indexes = count_freq.get(n, [])
            curr_indexes.append(i)
            count_freq[n] = curr_indexes

        for i, n in enumerate(nums):
            diff_indexes = count_freq.get(target - n, [])
            d = len(diff_indexes)
            if d > 0:
                j = 0
                while j < d and diff_indexes[j] == i:
                    j += 1
                if j < d:
                    return [i, diff_indexes[j]]

        return [0, 1]
        