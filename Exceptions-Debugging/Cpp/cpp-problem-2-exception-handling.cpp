/*
https://practice.geeksforgeeks.org/problems/c-exception-handling3103/1/?page=1&category[]=OOP&query=page1category[]OOP
*/


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxValue(int A, int B){
        // code here
        int ret_val;
        try {
            if (B == 0)
                throw B;
            ret_val = max(A + B, A - B);
            ret_val = max(A * B,ret_val);
            ret_val = max(A / B,ret_val);
        }
        catch (int B) {
            ret_val = -999999;
        }
        return ret_val;
    }
};

/*
Input
-5 5

Output
10


Input
-5 4

Output
-1

Input 
5 0

Output
inf
*/

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B;
        cin>>A>>B;
        
        Solution ob;
        int ans = ob.maxValue(A,B);
        if(ans == -999999)
            cout<<"inf\n";
        else
            cout<<ans<<"\n";
    }
    return 0;
}  // } Driver Code Ends
