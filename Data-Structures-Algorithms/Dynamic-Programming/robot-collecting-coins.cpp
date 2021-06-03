/*
https://binarysearch.com/problems/Collecting-Coins
*/

#include <bits/stdc++.h>
using namespace std;

int collect_coins(vector<vector<int>>& matrix) {
    
    if(matrix.size() == 0)
        return 0;

    vector<vector<int>> dp;
    for(auto row : matrix) 
        dp.push_back(row);

    for(int c = 1; c < matrix[0].size(); c++)
        dp[0][c] += dp[0][c - 1];

    for(int r = 1; r < matrix.size(); r++)
        dp[r][0] += dp[r - 1][0];

    for(int r = 1; r < matrix.size(); r++) {
        for(int c = 1; c < matrix[0].size(); c++) 
            dp[r][c] += max(dp[r - 1][c], dp[r][c - 1]);
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

/*
Input
2 4
0 3 1 1
2 0 0 4

Output
9

Explanation                    [r, r, r, d]
We take the following path: [0, 3, 1, 1, 4]                               
*/

int main() {
    int row, col, n;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> n;
            matrix[r][c] = n;
        }
    }
    cout << collect_coins(matrix) << endl;
    return 0;
}