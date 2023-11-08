https://leetcode.com/problems/search-insert-position/

class Solution {
    public int searchInsert(int[] nums, int target) {
        int low = 0, high = nums.length, mid = 0;

        while (low < high) {
            mid = low + (high - low) / 2;

            if (target <= nums[mid]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}