/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if (s.length() == NULL or s.length() == 1)
            return s.length();
        
        int maxVal = 1, start = 0, end = 0;
        
        vector<int> visited(255, 0);
        
        while(end < s.size()) {
            
            if ( ! visited[ (int)s[end] ]) {
                
                visited[ (int)s[end++] ] = 1;
                
                maxVal = max(maxVal, end - start);                
            }
            
            else
                visited[ (int)s[start++] ] = 0;
        }
        
        return maxVal;             
        
    }
};

int main() {

    /*
    pwwkew
    */

    /*
    3
    */
    
    Solution *soln = new Solution;
    string s;
    cin >> s;
    cout << soln -> lengthOfLongestSubstring(s) << endl;

    return 0;
}