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

class Solution2 {
private:
    string digits;
    unordered_map<char, string> mappings;

public:
    Solution2(string digits) {
        this -> digits = digits;
        this -> mappings['2'] = "abc";
        this -> mappings['3'] = "def";
        this -> mappings['4'] = "ghi";
        this -> mappings['5'] = "jkl";
        this -> mappings['6'] = "mno";
        this -> mappings['7'] = "pqrs";
        this -> mappings['8'] = "tuv";
        this -> mappings['9'] = "wxyz";
    }

    vector<string> make_combinations(int digit_index) {

        if(digit_index == this -> digits.length()) 
            return {""};
                
        vector<string> res_next, res;
        res_next = make_combinations(digit_index + 1);
        
        for (int j = 0; j < this -> mappings[digits[digit_index]].size(); j++) {
            for(int i = 0; i < res_next.size(); i++) {
                res.push_back(mappings[this -> digits[digit_index]][j] + res_next[i]);
            }
        }     
    
        return res;
    }

    vector<string> getAllComb() {     
        vector<string> res = make_combinations(0);
        return res;   
    }

    void printComb(vector<string> &comb) {
        for(auto &s : comb)
            cout << s << " ";
        cout << endl;
    }
};


int main() {

    /*
    4
    23
    */

    /*
    g h i
    ad ae af bd be bf cd ce cf
    */

    Solution *soln = new Solution();
    string digits;
    cin >> digits;
    vector<string> letter_comb = soln -> letterCombinations(digits);
    soln -> printComb(letter_comb);

    string digits2;
    cin >> digits2;
    Solution2 *soln2 = new Solution2(digits);    
    vector<string> letter_comb2 = soln2 -> getAllComb();
    soln2 -> printComb(letter_comb2);

    return 0;
}