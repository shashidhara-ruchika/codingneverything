/*
https://binarysearch.com/problems/Bomber-Man
*/

# include <bits/stdc++.h>

using namespace std;

/*
You are given a two-dimensional integer matrix of 1s and 0s, 
where a 1 represents a bomb and 0 represents an empty cell. 
When a bomb explodes, all the spaces along on the same row and column are damaged. 
Return the number of spaces you can stand in to not get damaged.
*/

class Solution { 
    private:
        vector<vector<int>> matrix;
        void input_matrix();
    public:
        Solution();
        int find_safe_cells();       
};

Solution :: Solution () {    
    this -> input_matrix();
}

void Solution :: input_matrix() {
    int row, col, num;
    cin >> row >> col;
    for (int r = 0; r < row; r ++) {
        vector<int> curr_row;
        for (int c = 0; c < col; c++) {
            cin >> num;
            curr_row.push_back(num);
        }
        this -> matrix.push_back(curr_row);
    }
}

int Solution :: find_safe_cells() {

    vector<bool> safe_rows(matrix.size(), true);
    vector<bool> safe_cols(matrix[0].size(), true);

    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[0].size(); c++) {
            if (matrix[r][c] == 1) {
                safe_rows[r] = false;
                safe_cols[c] = false;
            }
        }
    }

    int safe_cells = 0;
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[0].size(); c++) {
            if (safe_rows[r] && safe_cols[c])
                safe_cells++;
        }
    }
    return safe_cells;
}


/*
Input
3 3 
1 0 0 
0 1 0
0 0 0

Output 
1
*/

int main() {
    Solution *soln = new Solution();
    cout << soln -> find_safe_cells() << endl;
    return 0;
}