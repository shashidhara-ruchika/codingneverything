/*
https://leetcode.com/problems/first-bad-version/
*/

#include <bits/stdc++.h>

using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    
    int firstBadIndex;

    Solution(int bad) {
        firstBadIndex = bad;
    }

    bool isBadVersion(int n) {
        if (n < firstBadIndex)
            return false;
        else
            return true;
    }

    int firstBadVersion(int n) {
        
        int l = 1;
        int r = n;
        
        while (l < r) {
            
            int mid = l + (r - l)/2;
            
            if ( isBadVersion(mid) ) 
                r = mid;
            
            else 
                l = mid + 1;
        }
        
        return l;
    }
};

int main() {

    /*
    5
    4
    */

    /*
    4
    */
    int n, bad;
    cin >> n >> bad;
    Solution *soln = new Solution(bad);
    cout << soln -> firstBadIndex(n) << endl;

    return 0;
}