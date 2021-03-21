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
        
        if (nums.size() == 0)
            return 0;
        
        vector<int> dp_lis_len(nums.size(), 0);
        dp_lis_len[0] = 1;        
        
        int max_lis = 1;
        
        for(int dpi = 1; dpi < dp_lis_len.size(); dpi++) {
            
            int max_val = 0;
            
            for (int ni = 0; ni < dpi; ni++) {
                
                if (nums[ni] < nums[dpi])
                    max_val = max(max_val, dp_lis_len[ni]);
            }
            
            dp_lis_len[dpi] = max_val + 1;
            max_lis = max(max_lis, dp_lis_len[dpi]);
            
        }
        
        return max_lis;
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