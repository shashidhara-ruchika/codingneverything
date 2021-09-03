/*
https://leetcode.com/problems/longest-increasing-subsequence/
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
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


class Solution2
{
    public:
    //Function to find length of longest increasing subsequence.
    // https://youtu.be/Ns4LCeeOFS4
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
       vector<int> lis(n, 1);
       
       for (int i = 1; i < n; i++) {
           for (int j = 0; j < i; j++) {
               if (a[i] > a[j])
                    lis[i] = max(lis[j] + 1, lis[i]);
           }
       }
       
       int maxlis = lis[0];
       
       for (int i = 1; i < n; i++)
            maxlis = max(lis[i], maxlis);
       
       return maxlis;
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