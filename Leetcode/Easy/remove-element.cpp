/*
https://leetcode.com/problems/remove-element/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int nums_len = nums.size();
        if (nums_len < 0)
            return 0;
        
        int slow = 0;
        for(int fast = 0; fast < nums_len; fast++) {
            
            if(nums[fast] != val) {
                nums[slow] = nums[fast];            
                slow++;
            }
        }
        
        return slow;
    }

    vector<int> inputArr() {
    
        int n, v;
        cin >> n;
        vector<int> arr;
        while(n-- > 0) {
            cin >> v;
            arr.push_back(v);
        }
        return arr;
    }        
};

int main() {

    /*
    8
    0 1 2 2 3 0 4 2
    2
    */

   /*
   5
   */
    
    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    int val;
    cin >> val;
    
    cout << soln -> removeElement(arr, val) << endl;

    return 0;
}