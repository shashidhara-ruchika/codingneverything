/*
https://leetcode.com/problems/valid-palindrome/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        
        int l = 0;
        int r = s.size() - 1;
        
        while (l < r) {
            
            if ( !isalnum(s[l]) ) 
                l++;                
            
            else if ( !isalnum(s[r]) )
                r--;
            
            else if( tolower(s[l]) != tolower(s[r]) )
                return false;
            
            else {
                l++;
                r--;
            }                  
        }
        
        return true;        
    }
};

int main() {

    /*
    A man, a plan, a canal: Panama
    */

    /*
    1
    */

    Solution *soln = new Solution;
    string s;
    cin >> s;
    cout << soln -> isPalindrome(s) << endl;

    return 0;
}