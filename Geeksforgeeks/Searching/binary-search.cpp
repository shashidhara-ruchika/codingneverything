/*
https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1/
*/

//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int bin_search(int arr[], int l, int r, int k) {
        
        while (r >= l) {
            
            int m = l + (r - l)/2;
            
            if (arr[m] == k)
                return m;
                
            else if (arr[m] > k) 
                return bin_search(arr, l, m - 1, k);
                
            else
                return bin_search(arr, m + 1, r, k);
        }
        
        return -1;
    }
    
    int binarysearch(int arr[], int n, int k){
        // code here
        return bin_search(arr, 0, n - 1, k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        int found = ob.binarysearch(arr,N,key);
        cout<<found<<endl;
    }
}

  // } Driver Code Ends
