/*
https://practice.geeksforgeeks.org/problems/get-minimum-squares0538/1/
*/

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
	int MinSquares(int n)
	{
	    if (n <= 3)
	        return n;
	        
	    vector<int> sq_table(n + 1);
	    
	    sq_table[0] = 0;
	    sq_table[1] = 1;
	    sq_table[2] = 2;
	    sq_table[3] = 3;
	    
	    for (int i = 4; i <= n; i++) {
	        
	        sq_table[i] = i;
	        
	        for (int j = 1; j <= ceil(sqrt(i)); j++) {
	            
	            int temp = j * j;
	            
	            if (temp > i)
	                break;
	            else
	                sq_table[i] = min(sq_table[i], sq_table[i - temp] + 1);
	        }
	        
	    }
	    
	    int res = sq_table[n];
	    sq_table.clear();
	    
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends