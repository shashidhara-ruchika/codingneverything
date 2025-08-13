
# https://leetcode.com/problems/container-with-most-water/submissions/1218664164/

# https://neetcode.io/problems/max-water-container?list=neetcode150


class Solution:
    def maxArea(self, heights: List[int]) -> int:

        l = 0
        r = len(heights) - 1
        max_area = 0

        while l < r:
            area = (r - l) * min(heights[l], heights[r])
            max_area = max(max_area, area)

            # To maximize this, you want the lines to be both far apart and tall, but there’s a trade-off
            # so moving the pointer at the shorter side gives you 
            # the only possibility for finding a larger area by potentially increasing height. 
            # This is why the two-pointer technique (starting at both ends and moving inward) works so efficiently.
            if heights[l] <= heights[r]:
                l += 1
            else:
                r -= 1

        return max_area

        
        