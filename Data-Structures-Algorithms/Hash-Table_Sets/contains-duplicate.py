# https://leetcode.com/problems/contains-duplicate/description/

# https://neetcode.io/problems/duplicate-integer?list=neetcode150

class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        unique_nums = set()
        for n in nums:
            if n in unique_nums:
                return True 
            else:
                unique_nums.add(n)
        return False

        