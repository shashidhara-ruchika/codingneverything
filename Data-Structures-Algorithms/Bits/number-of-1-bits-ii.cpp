/*
https://leetcode.com/problems/number-of-1-bits/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int hammingWeight(uint32_t n) {
        
        int total_1_bits = 0;   // Keep track of count of bits = 1
        int mask = 0;           
        
        for (int i = 0; i < 32; i ++) {
            // Shift only n from LSB to MSB & add to count if bit val = 1
            if ( (n >> i) & 1)
                total_1_bits ++;
            
        }
        return total_1_bits;
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