// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

import java.util.*;


public class MaxProfit {
    
        public int maxProfit(int[] prices) {
    
            int profit = 0;
            int buy = prices[0];
            boolean higher = false;
    
            for (int i = 1; i < prices.length; i++) {
                int sell = prices[i];
                if (sell > buy) {
                    profit = Math.max(profit, sell - buy);
                    higher = true;
                } else {
                    buy = sell;
                }
            }

            if (!higher && profit ==0) {
                return -1;
            }
    
            return profit;
            
        }
    

    public static void main(String[] args) {
        MaxProfit s = new MaxProfit();
        int[] prices = {10,7,7,1};
        System.out.println(s.maxProfit(prices));
    }
}
