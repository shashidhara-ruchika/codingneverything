/*
https://binarysearch.com/problems/Compress-String
*/

#include <bits/stdc++.h>
using namespace std;

string compress_str(string s) {
    string new_s;
    new_s += s[0];

    for(int i = 1; i < s.length(); i++) {
        if (s[i] != s[i - 1]) {
            new_s += s[i];
        }
    }
    return new_s;
}

int main() {
    string s; 
    cin >> s;
    string compressed_str = compress_str(s);
    cout << compressed_str << endl;
    return 0;
}