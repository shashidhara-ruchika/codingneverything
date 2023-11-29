// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    public int maxProfit(int[] prices) {

        int profit = 0;
        int buy = prices[0];

        for (int i = 1; i < prices.length; i++) {
            int sell = prices[i];
            if (sell > buy) {
                profit = Math.max(profit, sell - buy);
            } else {
                buy = sell;
            }
        }

        return profit;
        
    }
}