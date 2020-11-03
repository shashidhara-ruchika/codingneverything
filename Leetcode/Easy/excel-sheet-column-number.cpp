/*
https://leetcode.com/problems/excel-sheet-column-number/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        
        long long int sum = 0;
        long long int power = 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            // A is 65, but 1 -indexing so 64
            sum += (s[i] - 64) * power;
            power *= 26;
        }
        
        return sum;
    }
};

int main() {

    /*
    CV
    */

    /*
    100
    */
    
    Solution *soln = new Solution;
    string column;
    cin >> column;
    cout << soln -> titleToNumber(column) << endl;

    return 0;
}