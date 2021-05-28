/*
https://binarysearch.com/problems/Farthest-Point-From-Water
*/

/*
You are given a matrix matrix of 0s and 1s 
where 0 represents water and 1 represents land. 
Find the land with the largest Manhattan distance 
from water and return this distance. 
If there is no land or no water in the board, return -1.
*/

#include <bits/stdc++.h> 
using namespace std; 

vector<vector<int>>& input_matrix() {
    int row, col, num;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for(int r = 0; r < row; r++) {
        for (int c= 0; c < col; c++) {
            cin >> num;
            matrix[r][c] = num;
        }
    }
    return matrix;
}

int get_dist(vector<vector<int>>& matrix) {

    vector<vector<int>> dist(matrix.size(), vector<int>(matrix[0].size(), 0));
    queue<pair<int, int>> q;

    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[0].size(); c++) {
            if (matrix[r][c]) {
                dist[r][c] = 1000;
            }
            else {
                q.push({r, c});
            }
        }
    }

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        vector<int> move_row = {0,  0, 1, -1};
        vector<int> move_col = {1, -1, 0,  0};

        for (int m = 0; m < 4; m++) {
            int next_row = row + move_row[m];
            int next_col = col + move_col[m];
            if (next_row >= 0 && next_row < matrix.size() &&
                next_col >= 0 && next_col < matrix[0].size()) {
                    int next_dist = dist[next_row][next_col];
                    int new_dist = dist[row][col] + 1;
                    if (new_dist < next_dist) {
                        dist[next_row][next_col] = new_dist;
                        q.push({next_row, next_col});
                    }
            }
        }

    }

    int max_dist = 0;
    for (int r = 0; r < dist.size(); r++) {
        for (int c = 0; c < dist[0].size(); c++) {
            max_dist = max(max_dist, dist[r][c]);
        }
    }

    if (max_dist == 0 || max_dist == 1000)
        return -1;

    return max_dist;
}

/*
Input
3 4
1 1 1 1
0 1 1 1
0 0 1 0

Output
3

Explanation
Land at grid[0][2] has a Manhattan distance of 3 to nearest water.
*/

int main() {
    vector<vector<int>> matrix = input_matrix();
    cout << get_dist(matrix) << endl;
    return 0;
}