/*
https://leetcode.com/problems/house-robber/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    8, 1,  3, 10,  7
    8, 8, 11, 18, 18
    */

    int rob(vector<int>& nums) {
        
        if (nums.size() == 0)
            return 0;
        
        if (nums.size() == 1)
            return nums[0];
        
        if (nums.size() == 2)
            return max(nums[0], nums[1]);
        
        vector<int> running_total(nums.size(), 0);
        running_total[0] = nums[0];
        running_total[1] = max (nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++)             
            running_total[i] = max(nums[i] + running_total[i - 2], running_total[i - 1]);
        
        return running_total[nums.size() - 1];
    }

    void solve() {
        int n, num;
        cin >> n;
        vector<int> nums;
        while(n-- > 0) {
            cin >> num;
            nums.push_back(num);
        }
        cout << rob(nums) << endl;
    }
};


int main() {

    /*
    5
    8, 1,  3, 10,  7
    */
   
    /*
    18
    */

    Solution soln;
    soln.solve();

    return 0;
}