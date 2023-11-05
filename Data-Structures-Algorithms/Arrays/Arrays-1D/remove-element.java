// https://leetcode.com/problems/remove-element/submissions/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    public int removeElement(int[] nums, int val) {
        int p = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                int temp = nums[i];
                nums[i] = nums[p];
                nums[p] = temp;
                p++;
            }
        }
        return p;
    }
}