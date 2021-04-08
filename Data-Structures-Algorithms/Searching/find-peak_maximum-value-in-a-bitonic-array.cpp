/*
https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array3001/1#
*/

#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:

    int findPeak(int arr[], int n, int low, int high) 
    {
        int mid = low + (high - low) / 2;
        
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
            return mid;
        
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            return findPeak(arr, n, low, mid - 1);
        
        else
            return findPeak(arr, n, mid + 1, high);
    }
	
	int findMaximum(int arr[], int n) 
	{
	    int mid_index = findPeak(arr, n, 0, n - 1);
	    return arr[mid_index];
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
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends