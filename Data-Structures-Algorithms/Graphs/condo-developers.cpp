/*
https://binarysearch.com/problems/Condo-Developers
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maxPosHeight(vector<vector<int>>& matrix) {
    vector<int> rowmax(matrix.size(), 0);
    vector<int> colmax(matrix[0].size(), 0);

    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            rowmax[r] = max(rowmax[r], matrix[r][c]);
            colmax[c] = max(colmax[c], matrix[r][c]);
        }
    }

    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            if(rowmax[r] < colmax[c])
                matrix[r][c] = rowmax[r];
            else
                matrix[r][c] = colmax[c];
        }
    }

    return matrix;
}

vector<vector<int>>& input_matrix() {
    int row, col, num;
    vector<vector<int>> matrix(row, vector<int>(col, 0));
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> num;
            matrix[r][c] = num;
        }
    }
    return matrix;
}

void display_matrix(vector<vector<int>> &matrix) {
    for(int r = 0; r < matrix.size(); r++) {
        for(int c = 0; c < matrix[0].size(); c++) {
            cout << matrix[r][c] << endl;
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = input_matrix();
    vector<vector<int>> new_matrix = maxPosHeight(matrix);
    display_matrix(new_matrix);
    return 0;
}

/*
Example 1

Input
3 3
1 2 3
4 5 6
7 8 9

Output
3 3 3
6 6 6
9 9 9

Explanation
The west-east skyline is [3, 6, 9] and north-south skyline is [7, 8, 9]. 
We can increase everything in the first row to 3 and 
everything in the second row to 6 without changing the skylines.


Example 2

Input
3 3
4 4 3
5 5 3
7 8 3

Output
4 4 3
5 5 3
7 8 3

Explanation
The west-east skyline is [4, 5, 8] and north-south skyline is [7, 8, 3]. 
We can't increase any condominium's height without changing the skyline, 
so we return the same matrix.
*/