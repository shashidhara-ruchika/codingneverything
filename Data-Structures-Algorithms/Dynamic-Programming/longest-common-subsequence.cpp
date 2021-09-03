// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
// https://youtu.be/HgUOWB0StNE

/*
Example 1:

Input:
A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.
Example 2:

Input:
A = 3, B = 2
str1 = ABC
str2 = AC
Output: 2
Explanation: LCS of "ABC" and "AC" is
"AC" of length 2.
*/


#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int slen1, int slen2, string s1, string s2)
    {
        // your code here
        
        vector<vector<int>> lcs(slen1 + 1, vector<int> (slen2 + 1, 0));
        
        for (int i1 = 1; i1 < slen1 + 1; i1++) {
            
            for (int i2 = 1; i2 < slen2 + 1; i2++) {
            
                if (s1[i1 - 1] == s2[i2 - 1])
                    lcs[i1][i2] = lcs[i1 - 1][i2 - 1] + 1;
                
                else
                    lcs[i1][i2] = max(lcs[i1 - 1][i2], lcs[i1][i2 - 1]);
                    
            }
        }
        
        return lcs[slen1][slen2];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
