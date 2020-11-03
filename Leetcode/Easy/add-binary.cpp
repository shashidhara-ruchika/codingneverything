/*
https://leetcode.com/problems/add-binary/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
    
public:
    string addBinary(string a, string b) {
        
        string result = "";
        int sum = 0;
        
        int ai = a.length() - 1;
        int bi = b.length() - 1;
        
        while(ai >= 0 || bi >= 0 || sum == 1) {
            
            if (ai >= 0)
                sum += a[ai] - '0';
            else
                sum += 0;
            if (bi >= 0)
                sum += b[bi] - '0';
            else
                sum += 0;
            
            // append 1 if sum = 1 or 3, append 0 if sum = 0, 2 to result string
            result = char( sum % 2 + '0') + result;
            
            // make carry as next sum
            sum /= 2;
            
            ai--;
            bi--;              
        }
        return result;        
    }
};

int main() {

    /*
    101 11
    */

    /*
    1000
    */
   
    Solution *soln = new Solution;

    string a, b;
    cin >> a >> b;

    cout << soln -> addBinary(a,b) << endl;

    return 0;
}