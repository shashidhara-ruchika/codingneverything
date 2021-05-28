/*
https://binarysearch.com/problems/S-Expression-Evaluation
*/

#include <bits/stdc++.h> 
using namespace std; 

int eval(char op, int num1, int num2) {
    if (op == '+') 
        return num1 + num2;
    else if (op == '-')
        return num1 - num2;
    else if (op == '*')
        return num1 * num2;
    else // op == '/'
        return num1 / num2;
}

int eval_s_str(string s) {
    stack<char> stk_symbol;
    stack<int> stk_number;

    int i = 0;
    int is_negative = 1;
    while(i < s.size()) {
        char c = s.at(i);
        if (c == '(' || c == '+' || c == '*' || c == '/') {
            stk_symbol.push(c);
            i++;
        }
        else if (c == ')') {
            int num2 = stk_number.top();
            stk_number.pop();
            int num1 = stk_number.top();
            stk_number.pop();
            char op = stk_symbol.top();
            stk_symbol.pop();
            stk_number.push(eval(op, num1, num2));
            stk_symbol.pop();
            i++;
        }
        else if (c == '-') {
            char c_next = s.at(i+1);
            if (c_next == ' ') {
                stk_symbol.push(c);
            }
            else {
                is_negative = -1;
            }
            i++;
        }
        else if (c == ' ') {
            i++;
        }
        else { // number
            stringstream ss;
            while(s[i] != ' ' && s[i] != ')') {
                //cout << s[i] << endl;
                ss << s[i];
                i++;
            }
            stk_number.push(is_negative * stoi(ss.str())); 
            is_negative = 1;           
        }
        
    }
    return stk_number.top();
}

int main() {
    string s;
    cin >> s;
    cout << eval_s_str(s) << endl;
    return 0;
}