/*
https://leetcode.com/problems/diagonal-traverse/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        
        vector<int> diagonal_traverse;
        
        if(matrix.empty())
            return diagonal_traverse;
        
        int R_size = matrix.size(), C_size = matrix[0].size(), r = 0, c = 0;         
        
        // unitl all elements are within matrix size
        while(r < R_size && c < C_size) {
            
            // going upwards
            while(r >= 0 && c < C_size) {
                diagonal_traverse.push_back(matrix[r][c]);
                r--;
                c++;
            }
            // retrieving the last r & c
            r++;
            c--;
            
            // going right or downwards
            if(c < C_size - 1) 
                c++;
            else 
                r++;
            
            
            //going downwards
            while(c >= 0 && r < R_size) {
                diagonal_traverse.push_back(matrix[r][c]);
                r++;
                c--;
            }
            // retrieving the last r & c
            c++;
            r--;
            
            //going downwards or right
            if(r < R_size - 1) 
                r++;
            else 
                c++;
            
        }
        
        return diagonal_traverse;
    }

    vector<vector<int>> inputMatrix() {
        int m, n;
        cin >> m >> n;

        vector<vector<int>> matrix;
        while (m-- > 0) {
            vector<int> row;
            int n1 = n, num;
            while(n1-- > 0) {
                cin >> num;
                row.push_back(num);
            }
            matrix.push_back(row);
        }

        return matrix;
    }

    void displayDiagonalTraversal(vector<int> traversal) {
        for(auto x: traversal)
            cout << x << " ";
        cout << endl;
    }
};

int main() {

    /*
    3 4
    1  2  3  4
    5  6  7  8
    9 10 11 12
    */

    /*
    1 2 5 9 6 3 4 7 10 11 8 12
    */

    Solution *soln = new Solution;
    vector<vector<int>> matrix = soln -> inputMatrix();
    vector<int> diag_traversal = soln -> findDiagonalOrder(matrix);
    soln -> displayDiagonalTraversal(diag_traversal);

    return 0;
}