/*
https://binarysearch.com/problems/Sinking-Islands
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    private:
        vector<vector<int>> board;
    public:
        void input_graph();
        vector<vector<int>> sink_islands();
        void output_graph(vector<vector<int>>& b);
};

vector<vector<int>> Solution :: sink_islands() {
    vector<vector<int>> is_visited;
    for (int r = 0; r < board.size(); r++)
    {
        vector<int> v(board[0].size(), 0);
        is_visited.push_back(v);
    }

    queue<pair<int, int>> land;
    for (int r = 0; r < board.size(); r++)
    {
        if(board[r][0])
        {
            land.push({r, 0});
            is_visited[r][0] = 1;
        }

        if(board[r][board[0].size() - 1])
        {
            land.push({r, board[0].size() - 1});
            is_visited[r][board[0].size() - 1] = 1;
        }
    }

    for (int c = 0; c < board[0].size(); c++)    
    {
        if(board[0][c])
        {
            land.push({0, c});
            is_visited[0][c] = 1;
        }

        if(board[board.size() - 1][c])
        {
            land.push({board.size() - 1, c});
            is_visited[board.size() - 1][c] = 1;
        }         

    }

    while(land.size() != 0)
    {
        pair<int, int> cell = land.front();
        int curr_row = cell.first;
        int curr_col = cell.second;
        land.pop();

        if(curr_row - 1 > 0)
        {
            if (is_visited[curr_row - 1][curr_col] == 0 && board[curr_row - 1][curr_col])
            {
                is_visited[curr_row - 1][curr_col] = 1;
                land.push({curr_row - 1, curr_col});
            }
        }

        if(curr_row + 1 < board.size())
        {
            if (is_visited[curr_row + 1][curr_col] == 0 && board[curr_row + 1][curr_col])
            {
                is_visited[curr_row + 1][curr_col] = 1;
                land.push({curr_row + 1, curr_col});
            }
        }

        if(curr_col - 1 > 0)
        {
            if (is_visited[curr_row][curr_col - 1] == 0 && board[curr_row][curr_col - 1])
            {
                is_visited[curr_row][curr_col - 1] = 1;
                land.push({curr_row, curr_col - 1});
            }
        }

        if(curr_col + 1 < board[0].size())
        {
            if (is_visited[curr_row][curr_col + 1] == 0 && board[curr_row][curr_col + 1])
            {
                is_visited[curr_row][curr_col + 1] = 1;
                land.push({curr_row, curr_col + 1});
            }
        }

    }

    for (int r = 1; r < is_visited.size() - 1; r++)
    {
        for(int c = 1; c < is_visited[0].size() - 1; c++)
        {
            if(is_visited[r][c] == 0)
                board[r][c] = 0;
        }
    }
    return board;
}

void Solution :: output_graph(vector<vector<int>>& b) {
    for(int r = 0; r < b.size(); r++) {
        for(int c = 0; c < b[0].size(); c++) {
            cout << b[r][c] << endl;
        }
        cout << endl;
    }
}

void Solution :: input_graph() {
    int row, col, num;
    cin >> row >> col;
    for(int r = 0; r < row; r++) {
        vector<int> v(col, 0);
        for(int c = 0; c < col; c++) {
            cin >> num;
            v[c] = num;
        }
        board.push_back(v);
    }
}

/*
Input
3 4
1 0 0 0
0 1 1 0
0 0 0 0

Output
1 0 0 0
0 0 0 0
0 0 0 0

Explanation
The island in the middle [(1, 1), (1, 2)] is completely submerged.
*/

int main() {
    Solution *soln = new Solution();
    soln -> input_graph();
    vector<vector<int>> new_b = soln -> sink_islands();
    soln -> output_graph(new_b);
    return 0;
}