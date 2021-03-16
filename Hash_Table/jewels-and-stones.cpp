/*
https://leetcode.com/problems/jewels-and-stones/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        map<char, int> stones_freq;
       
        for (int i = 0; i < stones.length(); i++) {
        
            if ( stones_freq.find(stones[i]) == stones_freq.end() )
                stones_freq[stones[i]] = 1;
            
            else
                stones_freq[stones[i]] += 1;
        }
        
        int jewels_count = 0;
        
        for (int i = 0; i < jewels.length(); i++) {
            
            if ( stones_freq.find(jewels[i]) != stones_freq.end())
                jewels_count += stones_freq[jewels[i]];
        }
        
        return jewels_count;
        
    }
};

int main() {

    /*
    zZ
    zfadZZkjhz
    */

    /*
    4
    */

    string jewels, stones;
    cin >> jewels >> stones;

    Solution *soln = new Solution();
    cout << soln -> numJewelsInStones(jewels, stones) << endl;

    return 0;
}