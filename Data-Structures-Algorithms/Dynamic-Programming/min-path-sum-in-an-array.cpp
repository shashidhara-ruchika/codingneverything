// https://leetcode.com/problems/minimum-path-sum/

/*
Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right, 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
*/

/*
Input: grid = [[1,3,1],
               [1,5,1],
               [4,2,1]]
Output: 7
Explanation: 
Because the path 
1 (0,0) → 3 (0,1) → 1 (0,2) → 1 (1, 2) → 1 (2, 2)
minimizes the sum
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int rs = grid.size();
        int cs = grid[0].size();
        
        vector<vector<int>> cost(rs, vector<int> (cs, 0));
        
        // initialize cell cost with grid cost
        for (int r = 0; r < rs; r++) {
            for (int c = 0; c < cs; c++) {
                cost[r][c] = grid[r][c];
            }
        }
        
        // initialize row cost
        for (int c = 1; c < cs; c++)
            cost[0][c] += cost[0][c - 1];
        
        // initialize col cost
        for (int r = 1; r < rs; r++)
            cost[r][0] += cost[r - 1][0];
        
        for (int r = 1; r < rs; r++) {
            for (int c = 1; c < cs; c++) {
                cost[r][c] += min(cost[r - 1][c], cost[r][c - 1]);
            }
        }
        
        return cost[rs - 1][cs - 1];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int r, c;
        cin>>r>>c;
        vector<vector<int>> Matrix(r, vector<int>(c, 0));
        for(int i = 0;i < r;i++) {
            for(int j  = 0; j < c; j++)
                cin >> Matrix[i][j];
        }
        
        Solution ob;
        cout<<ob.minPathSum(Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends