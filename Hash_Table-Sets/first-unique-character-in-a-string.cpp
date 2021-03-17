/*
https://leetcode.com/problems/first-unique-character-in-a-string/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> char_freq;
        
        for (auto c: s) {
            if (char_freq.find(c) == char_freq.end())
                char_freq[c] = 1;
            else
                char_freq[c]++;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (char_freq[s[i]] == 1)
                return i;
        }
        
        return -1;
    }
};

int main() {

    /*
    loveleetcode
    */

    /*
    2
    */

    string s;
    cin >> s;

    Solution *soln = new Solution();
    cout << soln -> firstUniqChar(s);

    return 0;
}