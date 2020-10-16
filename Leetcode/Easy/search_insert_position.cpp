/*
https://leetcode.com/problems/search-insert-position/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
    
public:
    int searchInsert(vector<int>& nums, int target) {
        // to return lower bound - index which points to the element 
        //that is equal to or just greater than target
        
        int low = 0, high = nums.size(), mid;       
        
        while(low < high) {
            
            mid = low + (high - low)/ 2;
            
            // look for lower bound in left(smaller subarray)
            if (target <= nums[mid])
                high = mid;
            
            // look for lowerbound in right(larger subarray)
            else
                low = mid + 1;
        }
    
        return low;        
    }

    void solve() {
        
        int n, val, v;
        cin >> n;
        vector<int> arr;
        while(n-- > 0) {
            cin >> v;
            arr.push_back(v);
        }
        cin >> val;

        cout << searchInsert(arr, val) << endl;
    }
};

int main() {

    /*
    4
    1 3 5 6
    2
    */

    /*
    1
    */

    Solution mysoln;   
    mysoln.solve();
    
    return 0;
}