/*
https://binarysearch.com/problems/Largest-Elements-in-Their-Row-and-Column
*/

#include<bits/stdc++.h>
using namespace std;

bool isSingle(int row, int col, vector<vector<int>>& matrix) {
    int count = 0;
    for (int c = 0; c < matrix[0].size(); c++) {
        if (matrix[row][c]) {
            count++;
            if (count > 1)
                return false;
        }
    }
    count = 0;
    for (int r = 0; r < matrix.size(); r++) {
        if (matrix[r][col]) {
            count++;
            if (count > 1)
                return false;
        }
    }
    return true;
}

int solve1(vector<vector<int>>& matrix) {
    int count = 0;
    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            if (matrix[r][c] && isSingle(r, c, matrix)) {
                count++;
            }
        }
    }
    return count;
}

int solve0(vector<vector<int>>& matrix) {
    vector<int> row1s(matrix.size(), 0);
    vector<int> col1s(matrix[0].size(), 0);    
    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            if (matrix[r][c]) {
                row1s[r]++;
                col1s[c]++;
            }
        }
    }

    int count = 0;
    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            if (matrix[r][c] && row1s[r] == 1 && col1s[c] == 1) {
                count++;
            }
        }
    }
    return count;
}

vector<vector<int>>& input_matrix() {
    int row, col, num;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> num;
            matrix[r][c] = num;
        }
    }
    return matrix;
}

/*
Input
3 4
1 0 0 0
0 1 0 1
0 0 1 0

Output
2
*/

int main() {
    vector<vector<int>> matrix = input_matrix();
    cout << solve0(matrix) << endl;
    cout << solve1(matrix) << endl;
    return 0;
}