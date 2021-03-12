/*
https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
*/

/*
We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
*/

/*
For the final position of those chips pile, there are only two possibilities:

The final position is at the even position, or
The final position is at the odd position.
In the first case, we at least need to cost odd_cnt to move all the chips at the odd positions to the even positions. Similarly, in the second case, we at least need to cost even_cnt.

Therefore, min(even_cnt, odd_cnt) is the smallest possible cost.
*/

# include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int odd_count = 0, even_count = 0;
        
        for(int i = 0; i < position.size(); i++) {
            
            if (position[i] % 2)
                odd_count++;
            
            else
                even_count++;
        }
        
        return min(odd_count, even_count);
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr;
        while(n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }
};

int main() {
    
    /*
    5
    2 2 2 3 3
    */

    /*
    2
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    cout << soln -> minCostToMoveChips(arr) << endl;

    return 0;

}    