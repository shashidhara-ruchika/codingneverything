// https://www.interviewbit.com/problems/longest-palindromic-subsequence/


/*
Input: 
bebeed

Output:
3

Explanation:
0 b e b e e d
b 1 1 3 3 3 3 
e 1 1 1 3 3 3 
b 1 1 1 1 2 2 
e 1 1 1 1 2 2 
e 1 1 1 1 1 1 
d 1 1 1 1 1 1
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{

public: int solve(string A) {

    vector<vector<int>> dp(A.length(), vector<int>(A.length(), 1));

    for (int c = 1; c < A.length(); ++c) {

        for (int i = 0; i < A.length() - c; ++i) {
            
            int j = i + c;

            if (A[i] == A[j] && j - i == 1) 
                    dp[i][j] = 2;
            else if (A[i] == A[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            else 
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            
        }
        
    }

    for (int i = 0; i < A.length(); ++i) {
        for (int j = 0; j < A.length(); ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[0][A.length() - 1];
}

};



// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        string s1;
        cin>>s1;        // Take the string as input
        Solution ob;
        cout << ob.solve(s1) << endl;
    }
    return 0;
}
  // } Driver Code Ends
