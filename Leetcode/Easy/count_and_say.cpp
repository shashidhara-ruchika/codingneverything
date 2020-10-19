/*
https://leetcode.com/problems/count-and-say/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {    
private:
    
    string countAndSayString(string s) {
        
        if (s == "1") {
            return "11";
        }
        
        string concat;
        int i = 1;
        vector<pair<int, char>> freq;
        int count = 1;        
        while (i < s.length()) {
            
            if (s[i-1] != s[i]) {
                concat.push_back((char)(count + '0'));
                concat.push_back(s[i-1]);
                count = 1;
            }
            else 
                count ++;
            
            i++;            
        }                      
        concat.push_back((char)(count + '0'));
        concat.push_back(s[s.length() - 1]);
        
        return concat;
        
    }
    
public:
    string countAndSay(int n) {
        
        if (n == 1) 
            return "1";
        
        string s1 = "1";
        for (int i = 1; i < n; i++) 
            s1 = countAndSayString(s1);
        
        return s1;
        
    }

    void solve() {
        int n;
        cin >> n;
        cout << countAndSay(n) << endl;
    }
};

int main() {

    /*
    7
    */
    
    /*
    13112221
    */

    Solution soln;
    soln.solve();

    return 0;
}