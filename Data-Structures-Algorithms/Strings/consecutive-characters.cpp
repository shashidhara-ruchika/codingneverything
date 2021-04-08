/*
https://leetcode.com/problems/consecutive-characters/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        
        int curr_sum = 1, max_sum = 0;
        
        for(int i = 1; i < s.length(); i++) {
            
            if(s[i - 1] != s[i]) {
                max_sum = max(max_sum, curr_sum);
                curr_sum = 0;
            }
            curr_sum ++;
            
        }
        
        max_sum = max(max_sum, curr_sum);
        return max_sum;        
    }
};

int main() {
    
    /*
    leeeeetcode
    */

    /*
    5
    */
    Solution *soln = new Solution;

    string s;
    cin >> s;

    cout << soln -> maxPower(s) << endl;

    return 0;
}