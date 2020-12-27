/*
https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        
      int pos = 0, space_idx, str_len = s.length();

      while (pos < str_len) {

        //Get index of next space
        space_idx = s.find(" ", pos);

        //We have reached the last word, so get the string end
        if (space_idx == string::npos)
          space_idx = str_len;

        //Point front to current pos, and back to one char before space
        int fr = pos, bk = space_idx - 1;
        char ch;

        //swap chars in word until front is less than back
        while (fr < bk) {
          ch = s[fr];
          s[fr++] = s[bk];
          s[bk--] = ch;
        }

        //Position to next word in the string
        pos = space_idx + 1;

      }
      return s;
        
    }
};

int main() {
    
    string WordsString;
    cin >> WordsString;

    Solution *soln = new Solution;
    cout << soln -> reverseWords(WordsString) << endl;

    return 0;
}

