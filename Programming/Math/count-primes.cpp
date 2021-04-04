/*
https://leetcode.com/problems/count-primes/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        
        if (n < 2)
            return 0;
        
        // stores wether index is a prime number or not
        vector<int> isPrime(n, 1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        
        int count = 0, i = 2;
        
        // change values untill i < sqrt(n) or i * i < n
        for (i = 2; i * i < n; i++) {
            
            // if i is a prime number, make all multiples in isPrime = 0
            if (isPrime[i] == 1) {
                
                // to get all multiples, increment in steps of i up to n
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = 0;
                
                count++;
            }
        }
        
        while (i < n) {
            if (isPrime[i])
                count++;
            i++;
        }
        return count;
    }
};

int main() {
    
    /*
    25
    */

    /*
    9
    */

    Solution *soln = new Solution;
    int n;
    cin >> n;
    cout << soln -> countPrimes(n) << endl;

    return 0;
}
