/*
https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3238/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int max_count = 0, curr_count = 0;        
        
        if (nums[0] == 1) {
            curr_count++; 
            max_count = max(max_count, curr_count);
        }
            
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == 0) {
                max_count = max(max_count, curr_count);
                curr_count = 0;                
            }
            else {
                curr_count++;                
            }            
        }
        max_count = max(max_count, curr_count);
        return max_count;
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }
};

int main() {

    /*
    6
    1 1 0 1 1 1
    */

    /*
    3
    */
   
    Solution *soln = new Solution;   
    vector<int> A = soln -> inputArr();
    cout << soln -> findMaxConsecutiveOnes(A) << endl;

    return 0;
}