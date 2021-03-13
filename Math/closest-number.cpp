/*
https://practice.geeksforgeeks.org/problems/closest-number5728/1#
*/


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int closestNumber(int n , int m) {
        
        int q = n / m;
        int n_divisible_by_m = q * m;
        int next_closest_n_divisible_by_m;
        
        if ( (n * m) > 0 )
            next_closest_n_divisible_by_m = m * (q + 1);
            
        else
            next_closest_n_divisible_by_m = m * (q - 1);
            
        if ( abs(n - n_divisible_by_m) < abs(n - next_closest_n_divisible_by_m) )
            return n_divisible_by_m;
        else
            return next_closest_n_divisible_by_m;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        
        cin>>N>>M;

        Solution ob;
        cout << ob.closestNumber(N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends