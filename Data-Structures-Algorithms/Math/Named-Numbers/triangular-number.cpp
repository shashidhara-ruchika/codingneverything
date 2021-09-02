// https://practice.geeksforgeeks.org/problems/triangular-number2850/1#

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    int isTriangular(int N){
        //code here
        int sum = 0;
        int i = 1;
        
        while (sum < N) {
            sum += i;
            i++;
        }
        
        return (sum == N) ? 1 : 0;
    }
};


/*
55
*/

/*
1
*/

/*
1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 = 55
*/

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        cout<<ob.isTriangular(N)<<"\n";
    }
}  // } Driver Code Ends