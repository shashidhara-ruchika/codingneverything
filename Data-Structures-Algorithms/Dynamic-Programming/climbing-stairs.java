// https://leetcode.com/problems/climbing-stairs

class Solution {
    public int climbStairsMR(int n) {
        int[] dp = new int[n + 1];
        return climb(n, dp);
    }

    public int climb(int n, int[] dp) {
        if (n <= 1) return 1;
        if (dp[n] != 0) return dp[n];
        int left = climb(n - 1, dp);
        int right = climb(n - 2, dp);
        dp[n] = left + right;
        return dp[n];
    }

    public int climbStairs(int n) {
        int[] dp = new int[n + 1];

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
}
