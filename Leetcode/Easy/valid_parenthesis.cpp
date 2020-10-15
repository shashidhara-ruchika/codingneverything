/*
https://leetcode.com/problems/valid-parentheses/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stk;
        
        int i = 0, s_len = s.length();        
        
        while(i < s_len) {
            
            char c = s.at(i);
            
            if (c == '(' or c == '[' or c == '{')
                stk.push(c);
            
            else if (c == ')') {
                if (!stk.empty() and stk.top() == '(')
                    stk.pop();
                else 
                    return false;
            }
             
            else if (c == '}') {
                if (!stk.empty() and stk.top() == '{')
                    stk.pop();
                else 
                    return false;
            }                
            
            else {
                if (!stk.empty() and stk.top() == '[')
                    stk.pop();
                else 
                    return false;                
            }
            
            i++;
        }
        
        if (stk.empty()) 
            return true;
    
        else 
            return false;   
        
    }
};


int main() {
    
    Solution mysoln;
    
    string str;
    cin >> str;
    
    cout << mysoln.isValid(str);
    
    return 0;
}

