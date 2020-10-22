/*
https://leetcode.com/problems/length-of-last-word/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1, i, len = digits.size();
        
        for (i = len - 1; i >= 0; i--) {
            
            if (carry) {
                if (digits[i] < 9) {
                    digits[i]++;
                    return digits;
                }
                else {
                    digits[i] = 0;
                    carry = 1;
                }
            }            
            
        }
        
        if (carry)
            digits.insert(digits.begin(), 1);
        
        return digits;
        
    }

    void solve() {
        
        int n, num;
        cin >> n;
        vector<int> digits;
        while(n-- > 0) {
            cin >> num;
            digits.push_back(num);
        }

        vector<int> digits_plus_one = plusOne(digits);
        
        for (auto i : digits_plus_one) 
            cout << i << " ";   
        cout << endl;
    }
};

int main() {

    /*
    3
    399
    */

    /*
    400
    */

    Solution soln;
    soln.solve();

    return 0;

}