/*
https://leetcode.com/problems/hamming-distance/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /*
    1   (0 0 0 1)
    4   (0 1 0 0)
           ^   ^
    Output: 2
    */
    int hammingDistance(int x, int y) {
        int diff = x ^ y;
        int count1s = 0;
        while (diff != 0) {
            if (diff & 1)
                count1s++;
            diff >>= 1;            
        }
        return count1s;
    }
};

int main() {
    
    /*
    1
    4
    */

    /*
    2
    */

    Solution *soln = new Solution();
    int x, y;
    cin >> x >> y;
    cout << soln -> hammingDistance(x, y) << endl;

    return 0;
}