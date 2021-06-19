/*
https://binarysearch.com/problems/Column-Sort
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> colSort(vector<vector<int>>& matrix) {
    
    for (int col = 0; col < matrix[0].size(); col++) {
    
        vector<int> v(matrix.size(), 0);
    
        for (int row = 0; row < matrix.size(); row++) 
            v[row] = matrix[row][col];
    
        sort(v.begin(), v.end());

        for (int row = 0; row < matrix.size(); row++) 
            matrix[row][col] = v[row];

    }

    return matrix;
}

vector<vector<int>>& input_vec() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col, 0));
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> v[r][c];
        }
    }
    return v;
}

void print_vec(vector<vector<int>>& v) {
    for(int r = 0; r < v.size(); r++) {
        for(int c = 0; c < v[0].size(); c++) {
            cout << v[r][c] << " ";
        }
        cout << endl;
    }
}

/*
Input
3 4
10 20 30 12
5 5 3 4
0 10 7 8

Output
0 5 3 4
5 10 7 8
10 20 30 12
*/

int main() {
    vector<vector<int>> v = input_vec();
    vector<vector<int>> sv = colSort(v);
    print_vec(sv);
    return 0;
}