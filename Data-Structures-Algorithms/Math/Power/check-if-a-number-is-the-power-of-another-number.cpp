// https://practice.geeksforgeeks.org/problems/check-if-a-number-is-power-of-another-number5442/1#

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int isPowerOfAnother(long long X, long long Y){
        // code here 
        if (Y == 1)
            return 1;
            
        if (X == 1)
            return (Y == 1 || Y == 2) ? 1 : 0;
        
        long long ans = X;
        
        while (ans < Y) 
            ans *= X;
            
        return (ans == Y) ? 1 : 0;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long int X, Y;
        cin >> X >> Y;
        Solution ob;
        cout << ob.isPowerOfAnother(X,Y) << endl;
    }
    return 0; 
}   // } Driver Code Ends