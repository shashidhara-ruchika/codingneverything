/*
https://binarysearch.com/problems/Length-of-Longest-Balanced-Subsequence
*/

#include <bits/stdc++.h>

using namespace std;

int len_longest_balanced_subsequence(string s) {
    stack<char> stk;
    int i = 0;
    int total_count = s.length();
    while(i < s.length())
    {
        char c = s.at(i);

        if (c == '(')
        {
            stk.push(c);
        }
        else
        {
            if (c == ')' && !stk.empty() && stk.top() == '(')
            {
                stk.pop();
            }
            else
            {    
                total_count--;
            }
        }
        i++;
    }
    while (!stk.empty())
    {
        stk.pop();
        total_count--;
    }
    return total_count;
}

/*
Input
())(()

Output
4

Explanation
We can take the subsequence "()()"
*/

int main() {
    string s;
    cin >> s;
    cout << len_longest_balanced_subsequence(s) << endl;
    return 0;
}