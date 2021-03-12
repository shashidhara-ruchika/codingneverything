/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    vector<string> letter_comb;
    map<int, string> num_letter_comb;    
    
    vector<string> letterCombinations(string digits) {      
        
        if (digits.size() == 0)
            return letter_comb;
        
        num_letter_comb =  { {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},{9,"wxyz"}};
        
        string s = "";        
        
        append_letters(digits, s, 0);
        
        return letter_comb;     
        
    }
    
    
    void append_letters (string digits, string s, int pos) {
        
        if (digits.size() == s.size()) {
            
            letter_comb.push_back(s);
            return;
        }
        
        string possible_letters = num_letter_comb[digits[pos] - '0'];
        //cout << digits[pos] << " " << possible_letters << endl;
        
        for (int i = 0; i < possible_letters.size(); i++) {
            
            s.push_back(possible_letters[i]);
            append_letters(digits, s, pos + 1);
            s.pop_back();
        }            
    }


    void printComb(vector<string> letter_comb) {
        
        for (int i = 0; i < letter_comb.size(); i++) 
            cout << letter_comb[i] << " ";
        cout << endl;
    }
};


int main() {

    /*
    "23"
    */

    /*
    ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    */

    Solution *soln = new Solution();
    string digits;
    cin >> digits;
    vector<string> letter_comb = soln -> letterCombinations(digits);
    soln -> printComb(letter_comb);

    return 0;
}