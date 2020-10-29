/*
https://leetcode.com/problems/factorial-trailing-zeroes/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 52! = 80658175170943878571660636856403766975289505440883277824000000000000
    // number of trailing zeroes = 12
    // 10 = 5 * 2, 
    // Therefore we need to find the count of 5s and 2s
    // count of 5s is enough as every even number is divisible by 2, count of 2s >> count of 5s
    // but for every power of 5, an additional 5 is added hence we need to find:
    // the number of times n is divisble by 5, 25, 125, 625, 3125, ....
    int trailingZeroes(int n) {
        int div = 5;
        int num_trailing_zeroes = 0;
        while(n >= div) {
            num_trailing_zeroes += n/div;
            div *= 5;
        }
        return num_trailing_zeroes;
    }

    void solve() {
        int n;
        cin >> n;
        cout << trailingZeroes(n) << endl;
    }
};

int main() {

    /*
    52
    */

    /*
    12
    */
    
    Solution soln;
    soln.solve();

    return 0;
}

