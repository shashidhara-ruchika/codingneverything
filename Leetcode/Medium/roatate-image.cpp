/*
https://leetcode.com/problems/rotate-image/
*/

// Rotate matrix by 90deg

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate_by_rect(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for (int i = 0; i < (n + 1)/2; i++) {
            for (int j = 0; j < n/2; j++) {
                
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
    
    void rotate_by_traspose_reverse(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        // transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                
                if (i != j) {
                    
                    //swap(matrix[i][j], matrix[j][i]);
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
                
            }
        }
        
        // reverse
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < n/2; j++) {
                
                //swap(matrix[i][j], matrix[i][n - j - 1]);
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp;
                
            }
        }
        
    }

    vector<vector<int>> input_matrix() {
        int n, num;
        cin >> n;
        vector<vector<int>> matrix;
        for (int i = 0; i < n; i++) {
            vector<int> row(n);
            for (int j = 0; j < n; j++) {
                cin >> num;
                row[j] = num;
            }
            matrix.push_back(row);
        }
        return matrix;
    }

    void display_matrix(vector<vector<int>> mat) {

        int n = mat.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                cout << mat[i][j] << " ";
            cout << endl;
        }

    }
};


int main () {

    /*
    3
    1 2 3
    4 5 6
    7 8 9
    4
     5  1  9 11
     2  4  8 10
    13  3  6  7
    15 14 12 16
    */

    /*
    7 4 1
    8 5 2
    9 6 3
    15 13  2  5
    14  3  4  1
    12  6  8  9
    16  7 10  11
    */

    Solution *soln1 = new Solution();
    vector<vector<int>> mat1 = soln1 -> input_matrix();
    soln1 -> rotate_by_rect(mat1);
    soln1 -> display_matrix(mat1);

    Solution *soln2 = new Solution();
    vector<vector<int>> mat2 = soln2 -> input_matrix();
    soln2 -> rotate_by_rect(mat2);
    soln2 -> display_matrix(mat2);
    
    return 0;
}
