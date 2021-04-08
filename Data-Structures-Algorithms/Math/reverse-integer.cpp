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

    Solution *soln_str_conv = new Solution;
    int n1;
    cin >> n1;
    cout << soln_str_conv -> reverse_str(n1) << endl;   
    
    Solution *soln_numeric = new Solution;
    int n2;
    cin >> n2;
    cout << soln_numeric -> reverse_int(n2) << endl;  

    return 0;
}