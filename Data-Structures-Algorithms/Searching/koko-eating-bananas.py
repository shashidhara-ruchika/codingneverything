

# https://leetcode.com/problems/koko-eating-bananas/

class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        maxspeed = max(piles)
        minspeed = 1
        res = maxspeed

        while minspeed <= maxspeed:
            mid = (maxspeed + minspeed) // 2

            timetaken = 0
            for pile in piles:
                timetaken += math.ceil(pile/mid)
            
            if timetaken <= h:
                res = min(res, mid)
                maxspeed = mid - 1
            else:
                minspeed = mid + 1
                   
        return res
