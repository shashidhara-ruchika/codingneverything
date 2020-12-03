/*
https://leetcode.com/problems/valid-sudoku/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    bool isValidSudokuSet(vector<vector<char>>& board) {
        
        vector<unordered_set<int>> rows(9, unordered_set<int>());
        vector<unordered_set<int>> cols(9, unordered_set<int>());
        vector<unordered_set<int>> boxes(9, unordered_set<int>());
        
        for (int i = 0; i < 9; i++) {
            
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.') 
                    continue;
                
                if (rows[i].find(board[i][j]) == rows[i].end())
                    rows[i].insert(board[i][j]);
                else
                    return false;
                
                if (cols[j].find(board[i][j]) == cols[j].end())
                    cols[j].insert(board[i][j]);
                else
                    return false;
                
                int box_num = (i / 3) * 3 + j / 3;
                if (boxes[box_num].find(board[i][j]) == boxes[box_num].end())
                    boxes[box_num].insert(board[i][j]);
                else
                    return false;              
            }
            
        }
        
        return true;
    }

    vector<vector<char>> inputSudoku() {
        char num;
        vector<vector<char>> sudokuSet;
        for (int i = 0; i < 9; i++) {
            vector<char> row(9);
            for (int j = 0; j < 9; j++) {
                cin >> num;
                row[j] = num;
            }
            sudokuSet.push_back(row);
        }
        return sudokuSet;
    }
};

int main() {
    /*
    8 3 . . 7 . . . .
    6 . . 1 9 5 . . .
    . 9 8 . . . . 6 .
    8 . . . 6 . . . 3
    4 . . 8 . 3 . . 1
    7 . . . 2 . . . 6
    . . . 4 1 9 . . 5
    . . . . 8 . . 7 9
    */

    /*
    0
    */

    Solution *soln = new Solution();
    vector<vector<char>> sudokuSet = soln -> inputSudoku();
    cout << soln -> isValidSudokuSet(sudokuSet) << endl;
    
    return 0;
}