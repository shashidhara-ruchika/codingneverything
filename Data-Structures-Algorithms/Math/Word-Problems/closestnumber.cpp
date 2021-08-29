// https://practice.geeksforgeeks.org/problems/closest-number5728/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int closestNumber(int N , int M) {
        // code here
        
        bool is_negative = false;
        
        int n = abs(N);
        int m = abs(M);
        
        if (N < 0)
            is_negative = true;
            
        int rem_first = n % m;
        int rem_second = m - rem_first;
        
        if (rem_first < rem_second) {
            n -= rem_first; 
        }
        else {
            n += rem_second;
        }
        
        if (is_negative)
            n *= -1;
        
        return n;
    }
};

/*
26368 -4424 
*/

/*
26544
*/

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