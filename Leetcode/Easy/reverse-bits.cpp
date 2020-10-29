/*
https://leetcode.com/problems/reverse-bits/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t num = 0, power_place = 31;
        while(n != 0) {
            // shift bit by power places
            num += (n & 1) << power_place;
            
            // right shift n to get digits from MSB to LSB
            n = n >> 1;
            
            // reduce power places until 0
            power_place --;
        }
        return num;
    }

    void solve() {
        uint32_t n;
        cin >> n;
        cout << reverseBits(n) << endl;
    }
};

int main() {
    
    /*
    00000010100101000001111010011100
    */

    /*
    964176192 (00111001011110000010100101000000)
    */

    Solution soln;
    soln.solve();

    return 0;
}