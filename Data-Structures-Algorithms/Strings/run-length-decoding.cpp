/*
https://binarysearch.com/problems/Run-Length-Decoding
*/

#include <bits/stdc++.h>
using namespace std;

string run_length_decoding(string s) {
    stringstream ss;
    stringstream num;
    int i = 0;
    while (i < s.length()) {
        if (isdigit(s[i])) 
            num << s[i];
        else {
            int intnum = stoi(num.str());
            for (int j = 0; j < intnum; j++)
                ss << s[i];
            num.str("");
            num.clear();
        }
        i++;
    }
    return ss.str();
}

/*
Input
4a3b2c1d10a
Output
aaaabbbccdaaaaaaaaaa
*/

int main() {
    string s;
    cin >> s;
    cout << run_length_decoding(s) << endl;
    return 0;
}