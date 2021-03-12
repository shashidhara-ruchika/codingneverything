/*
https://leetcode.com/problems/maximum-subarray/
https://practice.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // using current max prod, current min prod and global max prod values using kadane's algorithm
    int maxProduct(vector<int>& nums) {
        
        int max_prod_val = nums[0];
        int min_prod_val = nums[0];
        int global_max_prod_val = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] < 0)
                swap(max_prod_val, min_prod_val);
            
            max_prod_val = max(max_prod_val * nums[i], nums[i]);
            min_prod_val = min(min_prod_val * nums[i], nums[i]);
            
            global_max_prod_val = max(global_max_prod_val, max_prod_val);
            
            cout << max_prod_val << " " << min_prod_val << " " << global_max_prod_val << endl;
        }
        
        return global_max_prod_val;
    }

    vector<int> inputArr() {

        int n, num;
        cin >> n;
        vector<int> arr;
        while (n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
        
    }
};

int main() {

    /*
    3
    -2 3 -4
    */

    /*
    24
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    cout << soln -> maxProduct(arr) << endl;
    
    return 0;
}
