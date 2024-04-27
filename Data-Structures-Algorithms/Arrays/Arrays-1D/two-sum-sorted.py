# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l = 0
        r = len(numbers) - 1
        while (l < r and numbers[l] + numbers[r] != target):
            if (numbers[l] + numbers[r] < target):
                l += 1
            else:
                r -= 1
        return [l + 1, r + 1]
        