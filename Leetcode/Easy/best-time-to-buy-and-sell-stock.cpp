/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        long int min_price = INT_MAX;
        long int max_profit = 0;
        
        for(int i = 0; i < prices.size(); i++) {
            
            if (prices[i] < min_price)
                min_price = prices[i];
            
            else if (prices[i] - min_price > max_profit)
                max_profit = prices[i] - min_price;
        }
        return max_profit;
    }

    vector<int> inputVec() {
        int n, num;
        cin >> n;
        vector<int> vec;
        while(n-- > 0) {
            cin >> num;
            vec.push_back(num);
        }
        return vec;
    }

    /*void solve() {

        int n, num;
        cin >> n;
        vector<int> prices;
        for(int i = 0; i < n; i++) {
            cin >> num;
            prices.push_back(num);
        }

        cout << maxProfit(prices) << endl;
    }*/
};

int main() {

    /*
    6
    7 1 5 3 6 4
    */

    /*
    5
    */

    Solution *soln = new Solution;
    vector<int> prices = soln -> inputVec();
    cout << soln -> maxProfit(prices) << endl;

    return 0;
}