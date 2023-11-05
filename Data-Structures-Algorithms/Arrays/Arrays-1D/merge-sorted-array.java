// https://leetcode.com/problems/merge-sorted-array/submissions/?envType=study-plan-v2&envId=top-interview-150

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int mi = m - 1, ni = n - 1, mp = m + n -1;

        while (mi >= 0 && ni >= 0) {
            if (nums1[mi] > nums2[ni]) {
                nums1[mp] = nums1[mi];
                mi--;
            } else {
                nums1[mp] = nums2[ni];
                ni--;
            }
            mp--;
        }

        while (mi >= 0) {
            nums1[mp] = nums1[mi];
                mi--;
                mp--;
        }

        while (ni >= 0) {
            nums1[mp] = nums2[ni];
                ni--;
                mp--;
        }
        
    }
}