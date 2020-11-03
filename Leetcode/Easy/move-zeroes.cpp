/*
https://leetcode.com/problems/move-zeroes/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void displayArray (vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) 
            cout << nums[i] << " ";
        cout << endl;
    }

    void moveZeroes(vector<int>& nums) {
        
        int curr_index = 0, lastnonzero_index = 0;
        
        //displayArray(nums);

        while (curr_index < nums.size()) {
            
            if(nums[curr_index] != 0) {
                swap(nums[lastnonzero_index], nums[curr_index]);
                lastnonzero_index++;
            }
            curr_index++;
            //displayArray(nums);
        }
        
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
/*
0  1  0 -3 12 
0  1  0 -3 12 
1  0  0 -3 12 
1  0  0 -3 12 
1 -3  0  0 12 
1 -3 12  0  0 
*/

int main() {
    /*
    5
    0 1 0 -3 12
    */
    
    /*
    1 -3 12 0 0
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    
    soln -> moveZeroes(arr);

    soln -> displayArray(arr);

    return 0;
}
