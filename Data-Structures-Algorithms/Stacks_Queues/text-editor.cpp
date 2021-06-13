/*
https://binarysearch.com/problems/Text-Editor
*/

#include <bits/stdc++.h>

using namespace std;

string editorOP(string s) {
    deque<char> dq;
    int si = 0;
    while(si < s.size()) {
        if(s[si] == '<' && si + 1 < s.size() && s[si + 1] == '-') {
            if(!dq.empty()) {
                dq.pop_back();
            }
            si += 2;
        }
        else {
            dq.push_back(s[si++]);
        }
    }
    stringstream ss;
    while(!dq.empty()) {
        ss << dq.front();
        dq.pop_front();
    }
    return ss.str();
}

int main() {
    string s;
    cin >> s;
    cout << editorOP(s) << endl;
    return 0;
}