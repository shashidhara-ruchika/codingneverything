/*
https://leetcode.com/problems/palindrome-number/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        
        string num_str = to_string(x);
        int num_str_len = num_str.length();
        
        for(int i = 0; i < num_str_len/2; i++) {
            
            if (num_str[i] != num_str[num_str_len - 1 - i])
                return false;
        }
        
        return true;
    }
};

int main () {

    /*
    12321
    */

    /*
    1
    */

    Solution *soln = new Solution;
    int n;
    cin >> n;
    cout << soln -> isPalindrome(n) << endl;
    return 0;

}