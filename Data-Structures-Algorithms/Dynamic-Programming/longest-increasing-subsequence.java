/*
https://leetcode.com/problems/longest-increasing-subsequence/
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
*/

class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        Arrays.fill(dp, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        int max = dp[0];
        for (int d : dp) {
            max = Math.max(d, max);
            System.out.print(d + " ");
        }
        
        return max;
    }
}