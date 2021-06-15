/*
https://leetcode.com/problems/russian-doll-envelopes/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canBeEnveloped(vector<int>& a, vector<int>& b) {
        return a[0] < b[0] && a[1] < b[1];
    }
    
    bool static comp(vector<int>& a, vector<int>& b) {
        if(a[0] == b[0])
            return a[1] < b[1];    
        
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        sort(envelopes.begin(), envelopes.end(), comp);
        
        vector<int> dp(envelopes.size(), 1);
        int max_envelopes = 1;
        
        for(int i = 1; i < envelopes.size(); i++) {
            
            int i_max_envelopes = 0;
            for(int j = 0; j < i; j++) {
                if(canBeEnveloped(envelopes[j], envelopes[i])) {
                    i_max_envelopes = max(dp[j], i_max_envelopes);
                }
            }
            
            dp[i] = i_max_envelopes + 1;
            
            max_envelopes = max(dp[i], max_envelopes);
            
        }
        
        return max_envelopes;
    }

    vector<vector<int>>& input_envelopes() {
        int n, w1, h1;
        cin >> n;
        vector<vector<int>> env(n, vector<int>(2, 0));
        for(int i = 0; i < n; i++) {
            cin >> w1 >> h1;
            env[i][0] = w1;
            env[i][1] = h1;
        }
        return env;
    }
};


/*
Input
4
5 4
6 4
6 7
2 3

Output
3

Explanation
The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
*/

int main() {
    Solution *soln = new Solution();
    vector<vector<int>> dolls = soln -> input_envelopes();
    cout << soln -> maxEnvelopes(dolls) << endl;
    return 0;
}
