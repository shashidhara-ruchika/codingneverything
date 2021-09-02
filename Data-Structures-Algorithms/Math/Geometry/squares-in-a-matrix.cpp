// https://practice.geeksforgeeks.org/problems/squares-in-a-matrix5716/1#


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long squaresInMatrix(int m, int n) {
        // code here
        
        long long sum = 0;
        
        while(m >= 1 && n >= 1) {
            
            sum += m * n;
            m--;
            n--;
        }
        
        return sum;
    }
};

/*
Input:
4 3

Output:
20

Explanation:
There are a total of 20 squares in a 4*3 matrix. 
4 * 3 = 12  // squares of length = 1
3 * 2 = 6   // squares of length = 2
2 * 1 = 2   // squares of length = 3

total squares = 12 + 6 + 2 = 20
*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m,n;
        
        cin>>m>>n;

        Solution ob;
        cout << ob.squaresInMatrix(m,n) << endl;
    }
    return 0;
}  // } Driver Code Ends