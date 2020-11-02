/*
https://leetcode.com/problems/isomorphic-strings/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> table;
        unordered_set<char> t_val;
        
        int i = 0;
        
        while (i < s.size()) {            
            
            if (table.find(s[i]) == table.end()) { 
                
                if (t_val.find(t[i]) == t_val.end()) {
                    table[s[i]] = t[i];
                    t_val.insert(t[i]);
                }
                else
                    return false;
            }
            
            else {
                if (table[s[i]] != t[i])
                    return false;
            }
            
            i++;
        }
        return true;
    }

    void solve() {
        string s, t;
        cin >> s >> t;
        cout << isIsomorphic(s, t) << endl;
    }
};

int main() {
    /*
    paper
    title
    */

    /*
    1
    */

    Solution soln;
    soln.solve();

    return 0;
}