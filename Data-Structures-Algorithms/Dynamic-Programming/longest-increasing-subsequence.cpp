/*
https://leetcode.com/problems/longest-increasing-subsequence/
*/

# include <bits/stdc++.h>

using namespace std;

/*
nums        10   9   2   5   3   7 101  18
dp_lis_len   1   1   1   2   2   3   4   4
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size(), 1);
        
        int max_len = 1;
        
        for(int i = 1; i < nums.size(); i++) {
            
            int i_max_len = 0;
            
            for (int j = 0; j < i; j++) {
                
                if(nums[i] > nums[j])
                    i_max_len = max(dp[j], i_max_len);
            }
            
            dp[i] = i_max_len + 1;
            
            max_len = max(dp[i], max_len);
        }
        
        return max_len;
    }

    vector<int> inputVec(int n) {
        vector<int> v;
        int num;
        while(n-- > 0) {
            cin >> num;
            v.push_back(num);
        }
        return v;
    }
};

/*
8
10 9 2 5 3 7 101 18
*/

/*
4
*/

int main() {

    int n;
    cin >> n;
    Solution *soln = new Solution();
    vector<int> v = soln -> inputVec(n);
    cout << soln -> lengthOfLIS(v) << endl;

    return 0;
}