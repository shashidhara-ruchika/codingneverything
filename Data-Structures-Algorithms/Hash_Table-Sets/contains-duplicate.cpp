/*
https://leetcode.com/problems/contains-duplicate/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> uniq;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if (uniq.find(nums[i]) == uniq.end())
                uniq.insert(nums[i]);
            else
                return true;
        }
        
        return false;        
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> num;
            arr[i] = num;
        }
        return arr;
    }
};

int main() {
    /*
    6
    1 2 3 2 1 1
    */

    /*
    0
    */

    Solution *soln = new Solution;
    
    vector<int> arr = soln -> inputArr();

    cout << soln -> containsDuplicate(arr) << endl;

    return 0;
}