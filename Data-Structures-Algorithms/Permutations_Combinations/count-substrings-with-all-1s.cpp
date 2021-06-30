/*
https://binarysearch.com/problems/Count-Substrings-With-All-1s
*/

#include <bits/stdc++.h>
using namespace std;

int count1substrings(string s) {

    if(s.length() == 0)
        return 0;
    
    int count = 0;
    int total_subsets = 0;

    for(int i = 0; i < s.length() - 1; i++) {
        
        if (s[i] == '0' && count != 0) {
            total_subsets += (count * (count + 1))/2;
            count = 0;
        }
        
        if (s[i] == '1') 
            count++;
    }

    if(s[s.length() - 1] == '1')
        count++;
    total_subsets += (count * (count + 1))/2;
 
    return total_subsets % 1000000007;
}

/*
Input
011101

Output
7
*/

int main() {
    string s;
    cin >> s;
    cout << count1substrings(s) << endl;
    return 0;
}