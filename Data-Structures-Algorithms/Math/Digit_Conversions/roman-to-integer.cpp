/*
https://leetcode.com/problems/roman-to-integer/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> roman_to_int = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        int s_len = s.length();
        int i, int_total = 0;
        char curr, prev;
        
        prev = s[0];
        i = 1;
        
        while(i < s_len) {
            
            curr = s[i];
            
            if ((prev == 'I' and (curr == 'V' or curr == 'X')) or (prev == 'X' and (curr == 'L' or curr == 'C')) or (prev == 'C' and (curr == 'D' or curr == 'M')))
                int_total -= roman_to_int[prev];
            else
                int_total += roman_to_int[prev];
            
            prev = curr;
            
            i++;
            
        }
                                                                   
        int_total += roman_to_int[s[s_len - 1]];
                                                                   
        return int_total;                
    }

    void solve() {
        
        string roman_numeral;
        cin >> roman_numeral;
        cout << romanToInt(roman_numeral) << endl;

    }
};

int main() {

    /*
    MCMXCIV
    */

    /*
    1994
    */

    Solution *soln = new Solution;
    string roman_numeral;
    cin >> roman_numeral;
    cout << soln -> romanToInt(roman_numeral) << endl;
    
    return 0;
}
