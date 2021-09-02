// https://practice.geeksforgeeks.org/problems/the-lazy-caterers-problem2527/1


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
   	int maximum_Cuts(int n){
   	    // Code here
   	    int i = 1;
   	    int cuts = 1;
   	    
   	    while (i <= n) {
   	        cuts += i;
   	        i++;
   	    }
   	    
   	    return cuts;
   	}    
};

/*
Example 1:

Input:
5

Output: 
16

Explanation:  16 pieces can be formed by making 5 cuts.



Example 2:

Input: 
3

Output: 
7

Explanation: 7 pieces can be formed by making 3 cuts.
*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.maximum_Cuts(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends