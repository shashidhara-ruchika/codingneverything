/*
https://leetcode.com/problems/sqrtx/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {        
        
        if(x == 0 || x == 1)
            return x;
        
        long long int l = 0, r = x/2, mid;
        while (l < r) {
            
            mid = l + (r -l)/2;
            
            // mid squared is equal or mid + 1 squared just greater than x
            if (mid * mid <= x && (mid+1) * (mid + 1) > x)
                return mid;
            // if mid sqaured is greater than x, search in smaller left array
            if (mid * mid > x)    
                 r = mid - 1;
            // if mid squared is smaller than x, search in larger right array
            else
                l = mid + 1;                
            
        }
        return l;               
    }

    void solve() {
        int x;
        cin >> x;
        cout << mySqrt(x) << endl;
    }
};

int main() {

    /*
    8
    */

    /*
    2
    */
    
    Solution soln;
    soln.solve();

    return 0;
}