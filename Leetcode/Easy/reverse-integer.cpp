/*
https://leetcode.com/problems/reverse-integer/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // numerical method
    int reverse_int(int x) {
        
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

    // conversion to string method
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
            return -(int)rev_num;
        
        else
            return (int)rev_num; 
        
        return 0;
                      
    }

    void solve_numeric() {        
        int n;
        cin >> n;
        cout << reverse_int(n) << endl;
    }

    void solve_str_conversion() {
        int n;
        cin >> n;
        cout << reverse_str(n) << endl;
    }
};

int main() {

    /*
    -5678
    6789
    */
    
    /*
    -8765
    9876
    */ 

    Solution soln_str_conv;
    soln_str_conv.solve_str_conversion();   
    
    // something else is being printed
    Solution soln_numeric;
    soln_numeric.solve_numeric();  

    return 0;
}