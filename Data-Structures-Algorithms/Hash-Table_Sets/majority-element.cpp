/*
https://leetcode.com/problems/majority-element/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // keep a frequency of elements & return when freq > nums.size()/2
    int majorityElement_maps(vector<int>& nums) {
        
        if (nums.size() == 1)
            return nums[0];
        
        unordered_map<int, int> freq;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if (freq.find(nums[i]) == freq.end())
                freq[nums[i]] = 1;
            
            else {                
                freq[nums[i]]++;
                if (freq[nums[i]] > floor(nums.size()/2))
                    return nums[i];                    
            }
        }
        return -1;
    }

    // when we sort, since majority elements = num of elements > half of num of elements, 
    // it must be present at the centre after it is sorted
    int majorityElement_sort(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

