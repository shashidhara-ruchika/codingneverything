/*
https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1
*/

#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pnarr;
	    vector<int> nnarr;
	    
	    for (int i = 0; i < n; i++) {
	        
	        if (arr[i] >= 0)
	            pnarr.push_back(arr[i]);
	            
	        else
	            nnarr.push_back(arr[i]);
	    }
	    
	    int pn = pnarr.size(), nn = nnarr.size(), pi = 0, ni = 0, i = 0;
	    
	    while(i < n && pi < pn && ni < nn) {
	        arr[i++] = pnarr[pi++];
	        arr[i++] = nnarr[ni++];
	    }
	    
	    while(pi < pn) 
	        arr[i++] = pnarr[pi++];
	        
	    while(ni < nn) 
	        arr[i++] = nnarr[ni++];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends