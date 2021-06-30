/*
https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1
*/

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    // Function to find the subarray with given sum k
    // arr: input array
    // n: size of array
    vector<int> subarraySum(int arr[], int n, int s){
        
        int curr_sum = arr[0], start = 0, end;
        
        for(end = 1; end <= n; end++) {
            
            while ( (curr_sum > s) && (start < end - 1) ) {
                
                curr_sum -= arr[start];
                start++;
                
            }
            
            if (curr_sum == s) 
                return {start + 1, end};
            
            if (end < n)
                curr_sum += arr[end];
            
        }
        
        return {-1};
        
    }
};

// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends