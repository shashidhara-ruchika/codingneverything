# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

# https://neetcode.io/problems/buy-and-sell-crypto?list=neetcode150

class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        l = 0
        r = 1
        max_profit = 0

        while r < len(prices):
            if prices[l] < prices[r]:
                curr_profit = prices[r] - prices[l]
                max_profit = max(max_profit, curr_profit)
            else:
                l = r
            r += 1
        
        return max_profit
        