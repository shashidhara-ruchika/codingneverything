/*
https://leetcode.com/problems/happy-number/
*/

# include <bits/stdc++.h>

using namespace std;

/*
Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    bool isHappy(int n) {
        
        // first happy number is 7
        if (n == 1)
            return true;        
        
        // next happy number is 7
        // all numbers when sum of digits squared is repeated, values fall from 0 to 6,
        // so iterations are performed till n > 6
        while (n > 6) { 
            
            // sum = sum of digits squared
            int sum = 0;
            
            while (n != 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            
            if (sum == 1)
                return true;
            
            // new n becomes current sum of digits squared, if sum != 1
            n = sum;
        }
        return false;        
    }

    void solve() {
        int n;
        cin >> n;
        cout << isHappy(n) << endl;
    }
};

int main() {
    
    /*
    25
    */

    /*
    0
    */

    Solution soln;
    soln.solve();

    return 0;
}