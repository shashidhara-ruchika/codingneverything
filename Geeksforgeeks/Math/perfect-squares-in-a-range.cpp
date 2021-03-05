/*
https://practice.geeksforgeeks.org/problems/perfect-squares-in-a-range2253/1/
*/



#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
  public:
    int numOfPerfectSquares(int a, int b) {
        // code here
        return floor(sqrt(b)) - ceil(sqrt(a)) + 1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.numOfPerfectSquares(a,b) << endl;
    }
    return 0;
}  // } Driver Code Ends