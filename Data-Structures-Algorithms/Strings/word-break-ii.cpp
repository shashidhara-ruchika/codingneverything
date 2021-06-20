/*
https://binarysearch.com/problems/Break-String-Into-Words
*/

#include <bits/stdc++.h>

using namespace std;

bool break_word(string s, set<string>& all_words, map<string, bool>& matches) {
    if (matches.find(s) != matches.end())
        return matches[s];
    
    if (s.size() == 0) 
        return true;

    for (int i = 1; i <= s.size(); i++) {
        if (
            all_words.find(s.substr(0, i)) != all_words.end() && 
            break_word(s.substr(i, s.size() - i), all_words, matches)
        ) {
            matches[s] = true;
            return true;
        }
            
    }
    matches[s] = false;
    return false;
}

bool haveWordBreak(vector<string>& words, string s) {
    set<string> all_words(words.begin(), words.end()); 
    map<string, bool> matches;
    return break_word(s, all_words, matches);
}

/*
Input
4
quick brown the fox
thequickbrownfox

Output
1

Explanation
We can break the string down into "the quick brown fox".
*/

int main() {
    int n;
    cin >> n;
    vector<string> words(n, "");
    for(int i = 0; i < n; i++)
        cin >> words[i];
    string s;
    cin >> s;
    cout << haveWordBreak(words, s) << endl;
    return 0;
}