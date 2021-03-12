/*
https://leetcode.com/problems/find-pivot-index/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

// find left sums in an array & right sums in another array 
// traverse again to find index where left sums == right sums
// takes O(n) extra space
    int pivotIndex(vector<int>& nums) {
        
        if (nums.size() == 0)
            return -1;
        
        vector<int> l_sum(nums.size(), 0);
        vector<int> r_sum(nums.size(), 0);
        
        l_sum[0] = nums[0];
        r_sum[nums.size() - 1] = nums[nums.size() - 1];
        
        for(int i = 1; i < nums.size(); i++) {
            l_sum[i] += l_sum[i - 1] + nums[i];
            r_sum[nums.size() - i - 1] += r_sum[nums.size() - i] + nums[nums.size() - i - 1];
        }
        
        for (int i = 0; i < nums.size(); i++) {
            //cout << l_sum[i] << " " << r_sum[i] << endl;
            if (l_sum[i] == r_sum[i])
                return i;
        }
        return -1;
    }

// instead of left sums & right sums array, find total sum first
// traverse the array & subtract nums[i] with total sum & check if curr total sum is the same
// takes O(1) extra space
    int pivotIndex_O1(vector<int>& nums) {
        
        if (nums.size() == 0)
            return -1;
        
        int total = accumulate(nums.begin(), nums.end(), 0);
        
        int curr_total = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            //cout << curr_total << " ";
            
            if (curr_total == total - curr_total - nums[i])
                return i;
            
            curr_total += nums[i];
        }
        
        return -1;
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr;
        while(n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }
};

int main() {
    
    /*
    6
    1 1 4 2 1 3
    6
    1 7 3 6 5 6
    */

    /*
    -1
    3
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    cout << soln -> pivotIndex(arr) << endl;

    Solution *soln_o1 = new Solution;
    vector<int> arr_o1 = soln_o1 -> inputArr();
    cout << soln_o1 -> pivotIndex_O1(arr_o1) << endl;

    return 0;
}

