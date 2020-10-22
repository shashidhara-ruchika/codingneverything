/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int nums_len = nums.size();
        
        if(nums_len == 0)
            return 0;
        
        int slow = 0;
        for(int fast = 1; fast < nums_len; fast++) {
            // if values at slow and fast pointer are not equal
            // just copy the fast pointer value to slow pointer value
            if(nums[slow] != nums[fast]) {
                slow++;
                nums[slow] = nums[fast];
            }  
        }
        return slow + 1;
    }

    void solve() {

        int n, v;
        cin >> n;
        vector<int> arr;
        while(n-- > 0) {
            cin >> v;
            arr.push_back(v);
        }

        int sorted_till_n = removeDuplicates(arr);
        cout << sorted_till_n << endl;
        
        /*
        for(int i = 0; i < sorted_till_n; i++) 
            cout << arr[i] << " ";
        cout << endl;
        */

    }
};

int main() {

    /*
    10
    0 0 1 1 1 2 2 3 3 4
    */

    /*
    5
    */
    
    Solution soln;
    soln.solve();   

    return 0;
}
