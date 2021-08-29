// https://practice.geeksforgeeks.org/problems/sum-of-all-prime-numbers-between-1-and-n4404/1#

//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
   	long long int prime_Sum(int n){
   	    // Code here
   	    int ub = n + 1;
   	    vector<int> isprime(ub, 1);
   	    isprime[0] = 0;
   	    isprime[1] = 0;
   	    
   	    long long sum_prime = 0;
   	    
   	    int num = 2;
   	    for (num = 2; num * num < ub; num++) {
   	        if (isprime[num]) {
   	            for (int i = num * 2; i < ub; i += num)
   	                isprime[i] = 0;
   	            sum_prime += num;
   	        }
   	    }
   	    
   	    while (num < ub) {
   	        if (isprime[num])
   	            sum_prime += num;
   	        num++;
   	    }
   	        
   	    
   	    return sum_prime;
   	}    
};

/*
1
6
*/

/*
10
*/

/*
2 + 3 + 5 = 10
*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		long long int ans = ob.prime_Sum(n);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends