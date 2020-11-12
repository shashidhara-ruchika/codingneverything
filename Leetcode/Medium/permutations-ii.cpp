/*
https://leetcode.com/problems/permutations-ii/
*/

# include <bits/stdc++.h>

using namespace std;

// Given a collection of numbers, nums, that might contain duplicates, 
// return all possible unique permutations in any order.

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> perms;
        
        sort(nums.begin(), nums.end());
        
        do {
            perms.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return perms;
        
    }
};
