/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        int i = 0, temp;
        
        while (i < s.size()/2) {
            
            if (s[i] != s[s.size() - i - 1]) {
                //swap(s[i], s[s.size() - i - 1]);
                temp = s[i];
                s[i] = s[s.size() - i - 1];
                s[s.size() - i - 1] = temp;
            }
            i++;
        }
        return;
    }

    vector<char> inputStr() {
        string s;
        cin >> s;
        vector<char> strs(s.begin(), s.end());
        return strs;
    }

    void printStr(vector<char> &s) {
        string str(s.begin(), s.end());
        cout << str << endl;
    }
};

int main() {
    
    /*
    hello
    */

    /*
    olleh
    */

    Solution *soln = new Solution;
    vector<char> charArr = soln -> inputStr();
    soln -> reverseString(charArr);
    soln -> printStr(charArr);

    return 0;
}
