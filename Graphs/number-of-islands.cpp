/*
https://leetcode.com/problems/number-of-islands/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
    
public:    
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() 
                    || grid[row][col] == '0' || visited[row][col] == true)
            return;
        
        visited[row][col] = true;
        
        // all dir = (0,1) (1,0) (0,-1) (-1,0)
        vector<int> row_dir = {0, 1, 0, -1};
        vector<int> col_dir = {1, 0, -1, 0};
        
        for (int i = 0; i < 4; i++) {
            dfs(grid, visited, row + row_dir[i], col + col_dir[i]);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int row_size = grid.size();
        int col_size = grid[0].size();
        
        vector<vector<bool>> visited(row_size, vector<bool>(col_size, false));
        
        int island_count = 0;
        
        for (int r = 0; r < row_size; r++) {
            
            for (int c = 0; c < col_size; c++) {
                
                if (grid[r][c] == '1' && ! ( visited[r][c] ) ) {
                    dfs(grid, visited, r, c);
                    island_count++;
                }
            }
        }
        
        return island_count;
    }

    vector<vector<char>> inputGrid() {
        int row, col;
        cin >> row >> col;
        char g;

        vector<vector<char>> grid(row, vector<char>(col, '0'));

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                cin >> g;
                grid[r][c] = g;
            }
        }

        return grid;
    }
};

int main() {

    /*
    4 5
    1 1 0 0 0
    1 1 0 0 0
    0 0 1 0 0
    0 0 0 1 1
    */
 
    /*
    3
    */

    Solution *soln = new Solution();
    vector<vector<char>> grid = soln -> inputGrid();

    cout << soln -> numIslands(grid) << endl;

    return 0;
}