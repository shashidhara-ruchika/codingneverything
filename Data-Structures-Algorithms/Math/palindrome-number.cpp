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

    int reverse_num(int num) {
        int rev_num = 0;
        int d = log10((double)abs(num));
        //cout << d << endl;
        while(num > 0) {
            rev_num += (num % 10) * pow(10, d);
            num /= 10;
            d--;
        }
        return rev_num;
    }

    bool isPalindrome2(int num) {
        int rev_num = reverse_num(num);
        //cout << rev_num;
        if (rev_num == num)
            return true;
        else
            return false;
    }
};

int main () {

    /*
    12321
    1234
    */

    /*
    1
    0
    */

    Solution *soln = new Solution;
    Solution *soln2 = new Solution;
    int n;
    cin >> n;
    cout << soln -> isPalindrome(n) << endl;
    cin >> n;
    cout << soln2 -> isPalindrome2(n) << endl;
    return 0;

}