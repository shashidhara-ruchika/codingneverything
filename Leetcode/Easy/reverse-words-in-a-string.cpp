/*
https://leetcode.com/explore/learn/card/array-and-string/204/conclusion/1164/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    string reverseWords(string &s) {
        
        reverse(s.begin(), s.end());
        
        int word_end = 0;
        
        for (int i = s.find_first_not_of(' '); i !=-1; ) {
            
            if (word_end != 0) 
                s[word_end++] = ' ';
            
            int start_word = word_end;
            
            while (i< s.size() && s[i] != ' ') 
                s[word_end++] = s[i++]; 
            
            reverse(s.begin() + start_word, s.begin() + word_end);
            
            i = s.find_first_not_of(' ', i);
        }
        
        s.resize(word_end);
        
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