/*
https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> sum_pairs;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if (sum_pairs.find(target - nums[i]) != sum_pairs.end())    
                return {i, sum_pairs[target - nums[i]]};              
                
            else
                sum_pairs[nums[i]] = i;  
            
        }
        return {0, 0};
    }  

    
    void solve() {

        int n, target, num;
        vector<int> nums;        
        
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        cin >> target;

        vector<int> sum_pair;

        sum_pair = twoSum(nums, target);
        cout << sum_pair[0] << " " << sum_pair[1] << endl;      
        
    }  
        
};

int main() {

    /*
    4
    2 7 11 15
    9
    */

    /*
    0 1
    */

    Solution soln;
    soln.solve();
    return 0;

}