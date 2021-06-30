/*
https://binarysearch.com/problems/Noisy-Palindrome
*/

#include <bits/stdc++.h>
using namespace std;

bool isLower(char c) {
    if(c - 'a' >= 0 && c - 'a' < 26)
        return true;
    return false;
}

bool isNoisyPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    while(l <= r) {
        if(!isLower(s[l]))
            l++;
        else if(!isLower(s[r]))
            r--;
        else if(isLower(s[l]) && isLower(s[r])) {
            if(s[l] != s[r])
                return false;
            else {
                l++;
                r--;
            }
        }
    }
    return true;
}

/*
Input
a92bcbXa

Output
1

Explanation
If we only consider the lowercase characters, 
then s is "abcba" which is a palindrome.
*/

int main() {
    string s;
    cin >> s;
    cout << isNoisyPalindrome(s) << endl;
    return 0;
}