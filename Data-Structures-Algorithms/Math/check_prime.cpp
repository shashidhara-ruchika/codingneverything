/*
https://www.hackerrank.com/challenges/30-running-time-and-complexity/problem
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class CheckPrime {
    public:        
        bool check_prime(int n) {
            if (n < 2)
                return false;
                
            if (n == 2 || n == 3)
                return true;
                
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0)
                    return false;
            }
            return true;
        }
};

/*
Sample Input

3
12
5
7

Sample Output

Not prime
Prime
Prime
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;    
    CheckPrime *cp = new CheckPrime();          
    bool is_prime;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
         is_prime = cp -> check_prime(num);
        if(is_prime) 
            cout << "Prime\n";
        else 
            cout << "Not prime\n";
       
    }
    return 0;
}

