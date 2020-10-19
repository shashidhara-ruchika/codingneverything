/*
https://leetcode.com/problems/maximum-subarray/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // using current and global sum values using kadane's algorithm
    // A -2  1 -3  4 -1  2  1 -5  4
    // C -2  1 -2  4  3  5  6 -1  4
    // G -2  1  1  4  4  5  6  6  6
    int maxSubArray(vector<int>& nums) {
        
        int len = nums.size();
        
        if(len == 1)
            return nums[0];
        
        vector<long int> curr_sum(len);
        vector<long int> global_sum(len);
        
        curr_sum[0] = (long int)nums[0];
        global_sum[0] = (long int)nums[0];
        
        for(int i = 1; i < len; i++) {            
            curr_sum[i] = max(curr_sum[i - 1] + (long int)nums[i], (long int)nums[i]);
            global_sum[i] = max(global_sum[i - 1], curr_sum[i]);
        }
        
        return global_sum[len - 1];
    }

    void solve() {

        int n, num;
        cin >> n;
        vector<int> arr;
        while (n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        cout << maxSubArray(arr) << endl;
    }
};

int main() {

    /*
    9
    -2  1 -3  4 -1  2  1 -5  4
    */

    /*
    6
    */

    Solution soln;
    soln.solve();
    
    return 0;
}