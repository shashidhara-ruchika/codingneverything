/*
https://leetcode.com/problems/missing-number/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int size = nums.size();
        
        int sumn = size * (size + 1) / 2;
        
        int arrsum = 0;
        
        for (int i = 0; i < size; i++) 
            arrsum += nums[i];
        
        return sumn - arrsum;
    }

    vector<int> inputArr() {
        int  n, num;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; n++) {
            cin >> num;
            arr[i] = num;
        }
        return arr;
    }
};

int main() {

    /*
    3
    3 0 1
    */

    /*
    2
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    cout << soln -> missingNumber(arr) << endl;

    return 0;
}