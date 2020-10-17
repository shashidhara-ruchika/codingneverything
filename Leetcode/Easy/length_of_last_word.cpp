/*
https://leetcode.com/problems/length-of-last-word/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord_from_front(string s) {
              
        int s_len = s.size(), c = 0;
        
        if(s_len == 0)
            return 0;
        
        vector<int> word_lens;
        
        for(int i = 0; i < s_len; i++) {
            
            if(s[i] == ' ') {               
                if(i != 0 && s[i - 1] != ' ')   // push the word count, only if the previous character was not ' '
                    word_lens.push_back(c);
                c = 0;
            }  
            else if(s[i] != ' ')
                c++;               
        }
        
        if(s[s_len - 1] != ' ')         // push the last word count, if last character != ' '
            word_lens.push_back(c);
        
        /*for (auto i : word_lens)
            cout << i << " ";*/
        
        if (word_lens.size() == 0)
            return 0;
        else
            return word_lens.back();        
    }

    int lengthOfLastWord_from_back(string s) {
              
        int s_len = s.size(), c = 0;
        
        if(s_len == 0)
            return 0;
        
        for(int i = s_len - 1; i >= 0; i--) {
            
            if(s[i] == ' ') {               
                if(i != s_len - 1 && s[i + 1] != ' ') {
                    return c;
                }                    
                c = 0;
            }  
            else if(s[i] != ' ')
                c++;               
        }       
        
        return c; // return the last word count
        
    }

    void solve_from_front() {

        string s;
        getline(cin,s);
        cout << lengthOfLastWord_from_front(s) << endl;
    }

    void solve_from_back() {

        string s;
        getline(cin,s);
        cout << lengthOfLastWord_from_back(s) << endl;
    }
};

int main() {


    /*
        Hello World    
         Cpp is awesome   
    */

    /*
    5
    7
    */

    Solution mysoln_from_front;
    mysoln_from_front.solve_from_front();

    Solution mysoln_from_back;
    mysoln_from_back.solve_from_back();
    
    return 0;
}