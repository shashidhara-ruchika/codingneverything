// https://leetcode.com/problems/subsets/

class Solution {

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        genSubsets(0, nums, new ArrayList<>(), result);
        return result;
    }

    public void genSubsets(int index, int nums[], List<Integer> subset, List<List<Integer>> result) {
        if (index >= nums.length) {
            result.add(subset);
            return;
        }
        
        genSubsets(index + 1, nums, new ArrayList<>(subset), result);
        subset.add(nums[index]);
        genSubsets(index + 1, nums, new ArrayList<>(subset), result);

    }
}