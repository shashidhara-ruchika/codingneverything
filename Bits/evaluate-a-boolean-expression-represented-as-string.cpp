/*
https://www.geeksforgeeks.org/evaluate-a-boolean-expression-represented-as-string/
*/

#include <bits/stdc++.h>

using namespace std;

/*
Given a string consisting of only 0, 1, A, B, C where
A = AND
B = OR
C = XOR
Calculate the value of the string assuming no order of precedence and evaluation is done from left to right.

Constraints – The length of string will be odd. It will always be a valid string.
*/

/*
AND A
0 0 0
0 1 0
1 0 0
1 1 1

OR  B
0 0 0
0 1 1
1 0 1
1 1 1

XOR C
0 0 0
0 1 1
1 0 1
1 1 1
*/

class Solution {
public:
    int evalBoolExpr(string s) {
        
        int val = s[0] - '0';

        int i = 1;

        while(i < s.length()) {

            if (s[i] == 'A') {
                if (val == 1 && s[i + 1] == '1')
                    val = 1;
                else
                    val = 0;
            }
            else if (s[i] == 'B') {
                if (val == 0 && s[i + 1] == '0')
                    val = 0;
                else 
                    val = 1;
                
            }
            else if (s[i] == 'C') {
                if (val == s[i + 1] - '0')
                    val = 1;
                else    
                    val = 0;
            }
            else {}

            i += 2;          
            
        }

        return val;
    }

};

int main() {

/*
1C1B1B0A0
*/

/*
0
*/

    string s;
    cin >> s;

    Solution *soln = new Solution;
    cout << soln -> evalBoolExpr(s) << endl;

    return 0;
}
