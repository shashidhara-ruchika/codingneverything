/*
https://leetcode.com/problems/permutations-ii/
*/

# include <bits/stdc++.h>

using namespace std;

// Given a collection of numbers, nums, that might contain duplicates, 
// return all possible unique permutations in any order.

class Solution {
public:
    vector<vector<int>> permuteUnique1(vector<int>& nums) {
        
        vector<vector<int>> perms;
        
        sort(nums.begin(), nums.end());
        
        do {
            perms.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        
        return perms;        
    }

    void nextPermutation(vector<int>& nums) {
        
        int i = nums.size() - 2;
        
        // finding the first decreasing element (valley)
        while(i >= 0 && nums[i + 1] <= nums[i])
            i--;
        
        if (i >= 0) {
            
            int j = nums.size() - 1;
            
            // find the number just greater than nums[i-1]
            while (j >= 0 && nums[j] <= nums[i])
                j--;
            
            // swap these numbers at positions i, j
            swap (nums[i], nums[j]);
            
        }
        // reverse array from i + 1 pos till the end
        reverse(nums.begin() + i + 1, nums.end());
    }   
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> perms;        
        
        sort(nums.begin(), nums.end());
        
        vector<int> initial_nums = nums;
        
        do {
            perms.push_back(nums);
            
            nextPermutation(nums);
            
        } while (nums != initial_nums);
        
        return perms;
    }

    void displayVec(vector<int>& nums) {
        
        for (auto x : nums)
            cout << x << " ";
        cout << endl;
        
    }

    vector<int> inputVec() {
        int n, num;
        cin >> n;
        vector<int> vec(n);
        for(int i = 0; i < n; i++){
            cin >> num;
            vec[i] = num;
        }
        return vec;
    }
};

int main() {

    /*
    4
    2 2 1 1
    3
    1 2 3
    */

    /*
    1 1 2 2
    1 2 1 2
    1 2 2 1
    2 1 1 2
    2 1 2 1
    2 2 1 1

    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1
    */

    Solution *soln1 = new Solution;
    vector<int> vec1 = soln1 -> inputVec();
    vector<vector<int>> all_perm1 = soln1 -> permuteUnique(vec1);
    for (auto perm : all_perm1) 
        soln1 -> displayVec(perm);
    cout << endl;

    Solution *soln = new Solution;
    vector<int> vec = soln -> inputVec();
    vector<vector<int>> all_perm = soln -> permuteUnique(vec);
    for (auto perm : all_perm) 
        soln -> displayVec(perm);
    cout << endl;

    return 0;
}
