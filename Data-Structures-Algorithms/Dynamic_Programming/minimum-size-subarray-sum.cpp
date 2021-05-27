/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        // keep sliding window left & right pointers
        // keep moving them until their sum is >= s & dist between right & left is minimum
        int ans = INT_MAX, left = 0, sum = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            
            sum += nums[right];
            
            while (sum >= s) {
                
                ans = min(ans, right - left + 1);
                
                sum -= nums[left++];
            }
            
        }
        
        if (ans != INT_MAX)
            return ans;
        else
            return 0;
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
    2 3 1 2 4 3
    7
    */

    /*
    2
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    int s;
    cin >> s;

    cout << soln -> minSubArrayLen(s, arr) << endl;

    return 0;
}
