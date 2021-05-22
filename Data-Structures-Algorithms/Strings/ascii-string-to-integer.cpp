/*
https://binarysearch.com/problems/ASCII-String-to-Integer
*/

#include <bits/stdc++.h>
using namespace std;

/*
Input
11aa32bbb5

Output
48

Explanation
Since 11 + 32 + 5 = 48
*/

int conv_str(string s) {
    int sum_val = 0;
    int char_val = 0;
    int d = 0;
    for(int i = s.length() - 1; i >= 0; i--) {
        int char_val = s[i] - '0';
        if(char_val >= 0 && s[i] - '0' <= 9)
        {
            //cout << char_val * pow(10, d) << " "; 
            sum_val += char_val * pow(10, d);
            d++;
        }
        else
        {
            d = 0;
        }
            
    }
    return sum_val;
}

int main() {
    string s;
    cin >> s;
    cout << conv_str(s) << endl;
    return 0;
}