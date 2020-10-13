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

    int reverse_str(int x) {
                
        bool neg = false;
        if (x < 0)
            neg = true;
        
        x = abs(x);
        
        string rev_str = to_string(x);    
        long int rev_num;
        
        std::reverse(rev_str.begin(), rev_str.end());
        
        try {
            rev_num = std::stol(rev_str);
        }
        catch (...) {
            return 0;
        }
        
        if (rev_num > INT_MAX or rev_num < INT_MIN)
            return 0;
        
        else if (neg)
            return -rev_num;
        
        else
            return rev_num; 
        
        return 0;
                      
    }
};

int main() {

    int n, ns;
    cin >> n;
    ns = n;

    Solution mysoln;
    n = mysoln.reverse(n);
    ns = mysoln.reverse_str(ns);
    cout << n << endl << ns << endl;

    return 0;
}