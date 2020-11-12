/*
https://leetcode.com/problems/next-permutation/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    1 5 8 4 7 6 5 3 1
          ^     ^
    
    1 5 8 5 7 6 4 3 1
            |       |

    1 5 8 5 1 3 4 6 7            
    */
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

    void displayVec(vector<int> &vec) {
        for (auto x: vec) 
            cout << x << " ";
        cout << endl;
    }
};

int main() {

    /*
    9
    1 5 8 4 7 6 5 3 1
    */

    /*
    1 5 8 5 1 3 4 6 7
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputVec();
    
    soln -> nextPermutation(arr);
    soln -> displayVec(arr);

    return 0;
}