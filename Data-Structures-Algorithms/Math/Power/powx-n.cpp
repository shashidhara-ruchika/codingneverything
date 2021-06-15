/*
https://leetcode.com/problems/powx-n/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Divide & Conquer Approach
    double rec_pow_Ologn(double x, int n) { 
        
        if ( !n )    
            return 1;
        
        double ans = 1;
        
        if (abs(n) % 2) 
            ans *= x;
        
        ans *= rec_pow_Ologn(x * x, abs(n) / 2);
        
        if (n > 0)
            return ans;
        else
            return 1 / ans;
    }
    
    // Brute Force Approach
    double rec_pow_On(double x, int n) {
        if(n == 1)
            return x;
        else if(n == -1)
            return 1/x;
        else if(n < 0)
            return (1/x) * rec_pow_On(x, n + 1);
        else
            return x * rec_pow_On(x, n - 1);
            
    }
    
    double myPow(double x, int n) {
        return rec_pow_Ologn(x, n);
    }
};

int main() {
    double n, x;
    cin >> n >> x;
    Solution soln;
    cout << soln.myPow(x, n) << endl;
}