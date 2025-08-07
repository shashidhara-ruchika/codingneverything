# https://leetcode.com/problems/longest-consecutive-sequence/

# https://neetcode.io/problems/longest-consecutive-sequence?list=neetcode150

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        if (len(nums)) == 0:
            return 0

        set_nums = set(nums)

        start_nums = []
        for n in set_nums:
            if n - 1 not in set_nums:
                start_nums.append(n)

        longest_count = 1
        count = 1
        for n in start_nums:
            while n + 1 in set_nums:
                count += 1
                n = n + 1
            longest_count = max(longest_count, count)
            count = 1
        
        longest_count = max(longest_count, count)
        return longest_count


class Solution2:
    def longestConsecutive(self, nums: List[int]) -> int:
        sorted_nums = sorted(set(nums))
        print(sorted_nums)

        if len(nums) == 0:
            return 0
        
        i = 1
        count = 1
        longest_count = 1

        for i in range(1, len(sorted_nums)):
            if sorted_nums[i] == sorted_nums[i - 1] + 1:
                count += 1
            else:
                longest_count = max(longest_count, count)
                count = 1
        
        longest_count = max(longest_count, count)
        return longest_count