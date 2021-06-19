/*
https://binarysearch.com/problems/Check-Palindrome
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;

    while(l <= r) {
        if(s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

/*
racecar
*/

/*
1
*/

int main() {
    string s;
    cin >> s;
    cout << isPalindrome(s) << endl;
    return 0;
}
