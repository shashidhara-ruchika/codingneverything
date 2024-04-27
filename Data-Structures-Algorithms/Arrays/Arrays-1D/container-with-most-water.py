
# https://leetcode.com/problems/container-with-most-water/submissions/1218664164/


class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height) - 1
        maxArea = 0

        while (l < r):
            area = (r - l) * min(height[l], height[r])
            
            maxArea = max(maxArea, area)

            if (height[r] < height[l]):
                r -= 1
            else:
                l += 1

        return maxArea
        