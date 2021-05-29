/*
https://binarysearch.com/problems/Multiple-Parentheses
*/

/*
Given a string s consisting of open and closed brackets "(" and ")", 
return the length of the longest substring in s that is a valid string of parentheses.
*/

#include <bits/stdc++.h>
using namespace std;

/*
C++ stack solution - At the begining, the start index is initialized with -1.

We'll use a stack which tracks down the index of "("" we've seen, and maintain a start index. 

When we see a ")", we try to pop up from the stack, and check the length we can make.
*/

int valid_substr_len(string s) {
    int len_substr = 0;
    stack<int> stk;
    stk.push(-1);

    int i = 0;
    while (i < s.size()) {
        
        if (s[i] == '(') 
            stk.push(i);
        
        else {
            cout << i << " " << stk.top() << endl;
            stk.pop();
            
            if (stk.empty())
                stk.push(i);

            else 
                len_substr = max(len_substr, i - stk.top());
        }
        i++;
    }

    return len_substr;
    
}

/*
Input
)(())(()

Output
4

Explanation
(()) is the longest substring with valid parantheses.
*/

int main() {
    string s;
    cin >> s;
    cout << valid_substr_len(s) << endl;
    return 0;
}