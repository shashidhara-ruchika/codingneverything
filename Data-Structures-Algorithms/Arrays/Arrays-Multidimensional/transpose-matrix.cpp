/*
https://binarysearch.com/problems/Transpose-of-a-Matrix
*/

# include <bits/stdc++.h>

using namespace std;

class Matrix_op {       
    public:
        vector<vector<int>>& input_matrix();
        vector<vector<int>>& transpose_matrix(vector<vector<int>> matrix);
        void print_matrix(vector<vector<int>>& matrix);        
};

vector<vector<int>>& Matrix_op :: input_matrix() {
    int row, col, num;
    cin >> row >> col;
    vector<vector<int>> matrix(row, vector<int> (col, 0));
    for (int r = 0; r < row; r ++) {
        for (int c = 0; c < col; c++) {
            cin >> num;
            matrix[r][c] = num;
        }
    }
    return matrix;
}

vector<vector<int>>& Matrix_op :: transpose_matrix(vector<vector<int>> matrix) {
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < r; c++) {
            if (r != c) {
                int temp = matrix[r][c];
                matrix[r][c] = matrix[c][r];
                matrix[c][r] = temp;
            }
        }
    }
    return matrix;
}

void Matrix_op :: print_matrix(vector<vector<int>>& matrix) {
    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[0].size(); c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
}

/*
Input
3 3
1 2 3
4 5 6
7 8 9

Output
1 4 7
2 5 8
3 6 9
*/

int main() {
    Matrix_op *m = new Matrix_op();
    vector<vector<int>> matrix = m -> input_matrix();
    vector<vector<int>> transposed_matrix = m -> transpose_matrix(matrix);
    m -> print_matrix(transposed_matrix);
    return 0;
}


