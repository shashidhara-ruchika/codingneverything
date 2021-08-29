// https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1#

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{

public: 
    
    long long int largestPrimeFactor(int N){
        // code here
        long long n = N;
        long long largest_prime_factor = 0;
        
        vector<long long> isprime(n + 1, 1);
        
        isprime[0] = 0;
        isprime[1] = 0;
        
        int i = 2;
        for (i = 2; i * i < n + 1; i++) {
            if (isprime[i]) {
                for (int f = i * 2; f < n + 1; f += i) {
                    isprime[f] = 0;
                }
            }
        }
        
        if (isprime[N])
            return N;
            
        long long factor = ceil(sqrt(N));
        while (factor >= 0) {
            if (isprime[factor] && N % factor == 0)
                return factor;
            factor++;
        }
        
        return 2;
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
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends