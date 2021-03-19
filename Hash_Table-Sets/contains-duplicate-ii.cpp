/*
https://leetcode.com/problems/contains-duplicate-ii/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<long long, long long> recent_index;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (recent_index.find(nums[i]) == recent_index.end())
                recent_index[nums[i]] = i;
            else {
                if (i - recent_index[nums[i]] <= k)
                    return true;
                else
                    recent_index[nums[i]] = i;
            }
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
    4
    1 2 3 1
    3
    */

    /*
    1
    */

    Solution *soln = new Solution;
    
    vector<int> arr = soln -> inputArr();
    int k;
    cin >> k;

    cout << soln -> containsNearbyDuplicate(arr, k) << endl;

    return 0;
}