/*
https://leetcode.com/problems/reverse-integer/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        
        bool neg = false;        
        if (x < 0)
            neg = true;
        
        x = abs(x);
        
        long int rev;      
        while (x > 0) {            
            rev = (rev * 10) + (x % 10);
            x /= 10;                   
        }
        
        if (rev > INT_MAX or rev < INT_MIN)
            return 0;
        else if (neg)
            return -rev;
        else
            return rev;          
              
    }
};

int main() {
    
    int n;
    cin >> n;

    Solution mysoln;
    n = mysoln.reverse(n);
    cout << n;

    return 0;
}