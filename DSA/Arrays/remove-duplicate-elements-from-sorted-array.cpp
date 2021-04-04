/*
https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/
*/

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        // code here
        if (n == 0 || n == 1)
            return n;
        
        int uni_ptr = 0;
        int arr_ptr = 0;
        
        for(; arr_ptr < n - 1; arr_ptr++) {
            
            if (a[arr_ptr] != a[arr_ptr + 1])
                a[uni_ptr++] = a[arr_ptr];
        }
        
        a[uni_ptr++] = a[n - 1];
        
        return uni_ptr;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}  // } Driver Code Ends