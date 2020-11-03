/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // since no limit is on the number of transactions & 
    // stocks are sold before new ones are bought
    int maxProfit_simple(vector<int>& prices) {
        
        int max_profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                max_profit += prices[i] - prices[i -1];
        }
        return max_profit;
    }

    // find first min valley and last max peak
    int maxProfit(vector<int>& prices) {
        
        int i = 0;
        int max_profit = 0;
        
        while (i < prices.size() - 1) {
            
            while (i < prices.size() - 1 && prices[i] >= prices[i + 1])
                i++;
            // subtract first min or valley
            max_profit -= prices[i];
            
            while (i < prices.size() - 1 && prices[i] <= prices[i + 1])
                i++;
            // add last max or peak
            max_profit += prices[i];           
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

};

int main() {

    /*
    6
    7 1 5 3 6 4
    5
    1 2 3 4 5
    */

    /*
    7
    4
    */

    Solution *soln1 = new Solution;
    vector<int> prices1 = soln1 -> inputVec();
    cout << soln1 -> maxProfit_simple(prices1) << endl;    

    Solution *soln2 = new Solution;
    vector<int> prices2 = soln1 -> inputVec();
    cout << soln1 -> maxProfit_simple(prices2) << endl;

    return 0;
}