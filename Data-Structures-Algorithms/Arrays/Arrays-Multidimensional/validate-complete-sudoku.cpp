/*
https://binarysearch.com/problems/Sudoku-Validator
*/

# include <bits/stdc++.h>

using namespace std;

class ValidateSudoku {
    private:
        vector<int> v;
        vector<vector<int>> matrix;
        void resetv();
        bool checkline();
        bool checkgrid(int row, int col);
        bool checkallgrids();
        bool checkallrowcol(char c);
    public:
        ValidateSudoku(vector<vector<int>>& matrix);
        bool validateSudoku();
};

ValidateSudoku :: ValidateSudoku(vector<vector<int>>& matrix) {
    this -> matrix = matrix;
    v.resize(10);
    resetv();
}

void ValidateSudoku :: resetv() {
    for(int i = 0; i < v.size(); i++)
        v[i] = 0;
}

bool ValidateSudoku :: checkline() {
    for(int i = 1; i < v.size(); i++) {
        if (v[i] != 1)
            return false;
    }
    return true;
}

bool ValidateSudoku :: checkgrid(int row, int col) {
    resetv();
    for(int r = row - 1; r <= row + 1; r++) {
        for(int c = col - 1; c <= col + 1; c++) {
            v[matrix[r][c]]++;
        }
    }
    if(!checkline())
        return false;
    return true;
}

bool ValidateSudoku :: checkallgrids() {
    for(int i = 1; i < 9; i += 3) {
        for(int j = 1; j < 9; j += 3) {
            if (!checkgrid(i, j))
                return false;
        }
    }
    return true;
}

bool ValidateSudoku :: checkallrowcol(char rc) {
    for(int p = 0; p < 9; p++) {
        resetv();
        for(int q = 0; q < 9; q++) {
            if (rc == 'r')
                v[matrix[p][q]]++;
            if (rc == 'c')
                v[matrix[q][p]]++;
        }
        if(!checkline())
            return false;
    }
    return true;
}

bool ValidateSudoku :: validateSudoku() {
    vector<int> v(10, 0);
    return 
    checkallrowcol('r') &&
    checkallrowcol('c') &&
    checkallgrids();
}

vector<vector<int>>& inputSudoku() {
    int num;
    vector<vector<int>> sudokuSet;
    for (int i = 0; i < 9; i++) {
        vector<int> row(9);
        for (int j = 0; j < 9; j++) {
            cin >> num;
            row[j] = num;
        }
        sudokuSet.push_back(row);
    }
    return sudokuSet;
}

/*
4 2 6 5 7 1 3 9 8
8 5 7 2 9 3 1 4 6
1 3 9 4 6 8 2 7 5
9 7 1 3 8 5 6 2 4
5 4 3 7 2 6 8 1 9
6 8 2 1 4 9 7 5 3
7 9 4 6 3 2 5 8 1
2 6 5 8 1 4 9 3 7
3 1 8 9 5 7 4 6 2
*/

/*
1
*/

int main() {
    vector<vector<int>> sudoku = inputSudoku();
    ValidateSudoku vs(sudoku);
    cout << vs.validateSudoku() << endl;
    return 0;
}