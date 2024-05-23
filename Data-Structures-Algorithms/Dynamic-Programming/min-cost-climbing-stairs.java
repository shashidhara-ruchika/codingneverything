// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
    public int minCostClimbingStairsX(int[] cost) {
        return 0;
    }

    // recursion
    public int minCostClimbingStairsR(int[] cost) {
        int n = cost.length;
        return Math.min(minCostR(cost, n - 1), minCostR(cost, n - 2));
    }

    public int minCostR(int[] cost, int n) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) return cost[n];
        return cost[n] + Math.min(minCostR(cost, n - 1), minCostR(cost, n - 2));
    }


    // memoization

    int[] dp;

    public int minCostClimbingStairsMR(int[] cost) {
        int n = cost.length;
        dp = new int[n];
        return Math.min(minCostMR(cost, n - 1), minCostMR(cost, n - 2));
    }

    public int minCostMR(int[] cost, int n) {
        if (n < 0) return 0;
        if (n == 0 || n == 1) return cost[n];
        if (dp[n] != 0) return dp[n];
        dp[n] = cost[n] + Math.min(minCostMR(cost, n - 1), minCostMR(cost, n - 2));
        return dp[n];
    }

    // dp (top down)
    public int minCostClimbingStairsDP(int[] cost) {
        int n = cost.length;
        int[] dp = new int[n];

        for (int i = 0; i < n; i++) {
            if (i < 2) dp[i] = cost[i];
            else dp[i] = cost[i] + Math.min(dp[i - 1], dp[i - 2]);
        }

        return Math.min(dp[n - 1], dp[n - 2]);
    }


    // o(1) space
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int i1 = cost[0];
        int i2 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + Math.min(i1, i2);
            i1 = i2;
            i2 = curr;
        }

        return Math.min(i1, i2);
    }

}