/*
https://binarysearch.com/problems/Overchoice
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> add_choice(vector<string> &pos, vector<string> &choices) {
    if(pos.size() == 0)
        return choices;

    vector<string> newPos;
    for(auto &p : pos) {
        for(auto &s : choices) {
            newPos.push_back(p + s);
        }
    }
    return newPos;
}


vector<string> get_all_perm(string s) {
    vector<string> pos;    
    int i = 0;
    while(i < s.size()) {
        if(s[i] == '[') {
            vector<string> choices;
            while(s[i] != ']') {
                int j = i + 1;
                while(s[j] != '|' && s[j] != ']') {
                    j++;                    
                }
                //cout << s.substr(i + 1, j - 1 - i) << endl;
                choices.push_back(s.substr(i + 1, j - 1 - i));
                i = j;
            }     
            pos = add_choice(pos, choices);
            i++;
        }
        else {
            int j = i + 1;
            while(j != s.size() && s[j] != '[') {
                j++;
            }
            vector<string> choice;
            choice.push_back(s.substr(i, j - i));
            pos = add_choice(pos, choice);
            i = j;
        }
    }
    return pos;
}

/*
Input
[a|b]with[x|y|z]

Output
awithx
awithy
awithz
bwithx
bwithy
bwithz

Explanation
We take every possible combination between "a" or "b" and 
"x" or "y" or "z". "with" is fixed.
*/

int main() {
    string s;
    cin >> s;
    vector<string> perm = get_all_perm(s);
    for(auto &p : perm) {
        cout << p << endl;
    }
    return 0;
}