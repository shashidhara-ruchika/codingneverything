// https://practice.geeksforgeeks.org/problems/nth-even-fibonacci-number1119/1#

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int nthEvenFibonacci(long long int N) {
        // code here
        long long fib_n2 = 0;
        long long fib_n1 = 1;
        
        long long fib_n;
        
        long long n = N * 3;    // even numbers occur every third number
        // ex: 0,1,1,2,3,5,8, ...
        // ex: 2, 8, ...
        
        long long modn = 1000000007;
        
        
        for (long long i = 2; i <= n; i++) {
            
            fib_n = (fib_n2 % modn + fib_n1 % modn) % modn;
            
            fib_n2 = fib_n1 % modn;
            fib_n1 = fib_n % modn;
        }
        
        return fib_n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthEvenFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends