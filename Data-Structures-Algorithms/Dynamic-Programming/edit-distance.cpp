// https://practice.geeksforgeeks.org/problems/edit-distance3702/1
// https://youtu.be/Thv3TfsZVpw

/*
Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

Insert
Remove
Replace
 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.
Example 2:

Input : 
s = "gfg", t = "gfg"
Output: 
0
Explanation: Both strings are same.
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        
        // note 
        // - heading : changed  string t
        // | heading : original string s
        
        vector<vector<int>> ed(s.length() + 1, vector<int>(t.length() + 1, 0));
        
        // initialize 0th row
        for (int ti = 1; ti < t.length() + 1; ti++) {
            ed[0][ti] = ti;
        }
        
        // inititalize 0th col
        for (int si = 1; si < s.length() + 1; si++) {
            ed[si][0] = si;
        }
        
        
        for (int si = 1; si < s.length() + 1; si++) {
            
            for (int ti = 1; ti < t.length() + 1; ti++) {
                
                if (s[si - 1] == t[ti - 1])
                    ed[si][ti] = ed[si - 1][ti - 1];
                
                else {
                    ed[si][ti] = min(ed[si - 1][ti] + 1, ed[si][ti - 1] + 1);
                    ed[si][ti] = min(ed[si][ti], ed[si - 1][ti - 1] + 1);
                }
            }
        }
        
        return ed[s.length()][t.length()];
        
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends