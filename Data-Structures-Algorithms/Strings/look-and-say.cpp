/*
https://binarysearch.com/problems/Look-and-Say
*/

#include <bits/stdc++.h>

using namespace std;

string get_next(string s)
{
    string next_s;
    int i = 1;
    int count = 1;
    while(i < s.length())
    {        
        if(s[i-1] == s[i])
        {
            count++;
        }
        else
        {
            next_s += to_string(count) + s[i-1];
            count = 1;
        }
        i++;
    }
    if (s[s.length() - 2] == s[s.length() - 1])
    {
        next_s += to_string(count) + s[s.length() - 1];
    }
    else
    {
        next_s += to_string(1) + s[s.length() - 1];
    }
    return next_s;
}

string solve(int n) {
    string s = "1";
    if (n == 1)
        return "1";
    string next_s;
    while(n -- > 1)
    {
        next_s = get_next(s);
        s = next_s;
    }
    return next_s;
}

/*
Input
4

Output
1211

Explanation
1
11      <-  1 one
21      <-  2 ones
1211    <-  1 two, 1 one
111221  <-  1 one, 1 two, 2 ones
312211  <-  3 ones, 2 twos, 1 one
*/

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}