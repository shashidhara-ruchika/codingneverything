/*
https://leetcode.com/problems/spiral-matrix/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
     
        vector<int> spiral_traversal;
        
        if (matrix.empty())
            return spiral_traversal;
        
        // t - top, b - bottom, l - left, r - right
        
        int rbr = matrix.size() - 1, cbr = matrix[0].size() - 1, rtl = 0, ctl = 0;
        
        while (rtl <= rbr && ctl <= cbr) {
            
            // traverse c from l to r
            for (int c = ctl; c <= cbr; c++)
                spiral_traversal.push_back(matrix[rtl][c]);
                
            // traverse r from t to b
            for (int r = rtl + 1; r <= rbr; r++)
                spiral_traversal.push_back(matrix[r][cbr]);
        
            // traversals from r to l & from b to t to be pushed
            if (rtl < rbr && ctl < cbr) {
                
                // traverse c from r to l
                for(int c = cbr - 1; c > ctl; c--)
                    spiral_traversal.push_back(matrix[rbr][c]);
                
                // traverse r from b to t
                for(int r = rbr; r > rtl; r--)
                    spiral_traversal.push_back(matrix[r][ctl]);
            }
            
            // go to next inner layer
            rtl++;      // move downwards
            ctl++;      // move righwards
            rbr--;      // move upwards
            cbr--;      // move leftwards
        }
        
        return spiral_traversal;
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

    void displaySpiralTraversal(vector<int> traversal) {
        for(auto x: traversal)
            cout << x << " ";
        cout << endl;
    }
};

int main() {

    /*
    5 4
     1  2  3  4
     5  6  7  8
     9 10 11 12
    13 14 15 16
    17 18 19 20
    */

    /*
    1 2 3 4 8 12 16 20 19 18 17 13 9 5 6 7 11 15 14 10
    */

    Solution *soln = new Solution;
    vector<vector<int>> matrix = soln -> inputMatrix();
    vector<int> spiral_traversal = soln -> spiralOrder(matrix);
    soln -> displaySpiralTraversal(spiral_traversal);

    return 0;
}