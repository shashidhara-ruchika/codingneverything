/*
https://leetcode.com/problems/coin-change/
*/

# include <bits/stdc++.h>

using namespace std;

/*
    Input: coins = [1,2,5], amount = 11
    Output: 3
    Explanation: 11 = 5 + 5 + 1
*/

class Solution {
public:
    
    int getCoinChange(vector<int> &coins, int rem_amount, vector<int> &change_table) {
        
        if (rem_amount < 0)
            return -1;
        
        if (rem_amount == 0)
            return 0;
        
        if (change_table[rem_amount - 1] != 0)
            return change_table[rem_amount - 1];
        
        int min = INT_MAX;
        
        for (auto coin: coins) {
            
            int res = getCoinChange(coins, rem_amount - coin, change_table);
            
            if (res >= 0 && res < min)
                min = res + 1;
        }
        
        if (min == INT_MAX)
            change_table[rem_amount - 1] = -1;
        else
            change_table[rem_amount - 1] = min;
        
        return change_table[rem_amount - 1];
    }
    
    int coinChange_topBottom(vector<int>& coins, int amount) {
        if (amount < 1)
            return 0;
        
        vector<int> change_table(amount, 0);
        
        return getCoinChange(coins, amount, change_table);
    }
    
    
    int coinChange_bottomUp(vector<int> &coins, int amount) {
        
        int max_val = amount + 1;
        
        vector<int> change_table(amount + 1, max_val);
        
        change_table[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            
            for (auto coin: coins) {
                if (coin <= i)
                    change_table[i] = min(change_table[i], change_table[i - coin] + 1);
            }
        }
        
        if (change_table[amount] < max_val)
            return change_table[amount];
        else
            return -1;
    }

    vector<int> inputVector() {        
        int n, num;
        cin >> n;
        vector<int> vec;
        
        while (n-- > 0) {
            cin >> num;
            vec.push_back(num);
        }

        return vec;
    }
};

int main() {

    /*
    3
    1 2 5
    11
    1 
    2
    3
    */
    
    /*
    3
    -1
    */

    Solution *soln_td = new Solution();
    Solution *soln_bu = new Solution();

    int amount1, amount2;

    vector<int> coins1 = soln_td -> inputVector();
    cin >> amount1;
    cout << soln_td -> coinChange_topBottom(coins1, amount1);

    vector<int> coins2 = soln_bu -> inputVector();
    cin >> amount2;
    cout << soln_bu -> coinChange_topBottom(coins2, amount2);
    
    return 0;
    
}