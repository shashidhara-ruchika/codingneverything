// https://practice.geeksforgeeks.org/problems/last-two-digit-fibonacci3353/1#

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    
     // last 2 digits reappear after every 300 numbers
    int fibonacciDigits(long long N){
        
        long long F[300];
        
        F[1] = F[2] = 1;
        
        for (int i = 3; i < 300; i++)
        {
            // we mod with 100 to store only the last 2 digits.
            F[i] = (F[i-2]+F[i-1]) % 100;
        }
        
        return F[N %300];
    }
};

/*
Input:
255

Output:
70

Explanation:
The 255th fibonacci number is  875715953430-
18854458033386304178158174356588264390370.
Thus, last two digits are 7 and 0.
*/
// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        int ans=ob.fibonacciDigits(N);
        if(ans/10)
         cout<<ans;
        else
         cout<<0<<ans;
        cout<<"\n";  
    }
}  // } Driver Code Ends