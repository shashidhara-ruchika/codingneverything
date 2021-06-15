/*
https://leetcode.com/problems/fibonacci-number/solution/
*/

#include <bits/stdc++.h>
using namespace std;

// Find the nth Fibonacii Number
// 0 <= n <= 30
// Fib(0) = 0, Fib(1) = 1, Fib(2) = 1, Fib(3) = 2, Fib(4) = 3, Fib(5) = 5, ...

class Solution {
private:
    vector<int> fib_dp;
public:    
    
    int fib_vi(int n) {     // DP using 3 variables
        
        if (n < 2)
            return n;
        
        int fib_n = 1, fib_n_1 = 1, fib_n_2 = 0;
        
        for(int i = 2; i <= n; i++) {
            fib_n = fib_n_1 + fib_n_2;
            fib_n_2 = fib_n_1;
            fib_n_1 = fib_n;
        }
        
        return fib_n;
            
    }
    
    int fib_dpi(int n) {    // Iterative DP
        if (n < 2)
            return n;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        
        for(int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    Solution() {            // Constructor only required for Recursive DP
        this -> fib_dp.resize(31, 0);
        this -> fib_dp[1] = 1;
    }
    
    int fib_dpr(int n) {    // Recursive DP
        
        if(n < 2)
            return n;
        
        if(this -> fib_dp[n] != 0)
            return fib_dp[n];
        
        this -> fib_dp[n] = fib_dpr(n - 1) + fib_dpr(n - 2);
        
        return fib_dpr(n);
        
    }
    
};

int main() {
    Solution s;
    cout << s.fib_dpi(3) << endl;
    cout << s.fib_dpi(4) << endl;
    cout << s.fib_dpi(5) << endl;
    return 0;
}