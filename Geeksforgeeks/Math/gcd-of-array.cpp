/*
https://practice.geeksforgeeks.org/problems/gcd-of-array0614/1/
*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	int gcd2num(int a, int b) {
	    if ( a == 0)
	        return b;
	    return gcd2num(b % a, a);
	}
	
    int gcd(int N, int arr[])
    {
    	int gcd_res = arr[0];
    	
    	for (int i = 1; i < N; i++) {
    	    
    	    gcd_res = gcd2num(arr[i], gcd_res);
    	    
    	    if (gcd_res == 1)
    	        return 1;
    	}
    	
    	return gcd_res;
    }
};


// { Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}  // } Driver Code Ends