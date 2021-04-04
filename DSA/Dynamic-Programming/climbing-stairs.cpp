/*
https://leetcode.com/problems/climbing-stairs/
*/

# include <bits/stdc++.h>

using namespace std;


class Solution {

public:
    int count_ways_dp(int n) {
        
        if (n <= 2) 
            return n;
        
        vector<int> count_ways(n + 1);
        count_ways[0] = 0;
        count_ways[1] = 1;
        count_ways[2] = 2;
        
        for(int i = 3; i <= n; i++) {
            count_ways[i] = count_ways[i - 1] + count_ways[i - 2];
        }
        
        return count_ways[n];       
    }
    
    int count_ways_recursion(int n, vector<int> &memo) {
        
        if (n < 0)
            return 0;
        
        if (n == 0)
            return 1;
        
        // if value is present, return value
        if (memo[n] != -1) 
            return memo[n];
        
        // if value is not present, update the calculated value & return it
        memo[n] = count_ways_recursion(n - 1, memo) + count_ways_recursion(n - 2, memo);
        return memo[n];        
        
    }    

    int climbStairs_recursion(int n) {      
        
        vector<int> memo(n+1, -1);
        return count_ways_recursion(n, memo);              
    }

    int climbStairs_dp(int n) {
        return count_ways_dp(n);
    }

    /*void solve_dp() {
        int n;
        cin >> n;
        cout << climbStairs_dp(n) << endl;
    }

    void solve_recursion() {
        int n;
        cin >> n;
        cout << climbStairs_recursion(n) << endl;
    }*/
};

int main () {
    /*
    3
    5
    */

    /*
    3
    8
    */

    Solution *soln_dp = new Solution;
    int n1;
    cin >> n1;
    cout << soln_dp -> climbStairs_dp(n1) << endl;

    Solution *soln_rec = new Solution;
    int n2;
    cin >> n2;
    cout << soln_rec -> climbStairs_recursion(n2) << endl;

    return 0;
}