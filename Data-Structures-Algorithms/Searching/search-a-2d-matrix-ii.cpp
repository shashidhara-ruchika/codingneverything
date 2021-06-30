/*
https://leetcode.com/problems/search-a-2d-matrix-ii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
        return search(matrix, target, 0, matrix[0].size() - 1);        
        
    }
    
    bool search(vector<vector<int>>& matrix, int target, int r, int c){
         
        if (c < 0 || r > matrix.size() - 1)     // boundary conditions fail
             return false;
        
        if (matrix[r][c] == target)             // target found
            return true;
        
        else if (matrix[r][c] > target)         // move to previous col
             return search(matrix, target, r, c - 1);
        
        else                                    // move to next row
             return search(matrix, target, r + 1, c);
        
    }
    
};

/*
Input: 
4 5
1 4 7 11 15
2 5 8 12 19
3 6 9 16 22
10 13 14 17 
9

Output:
1

Input: 
4 5
1 4 7 11 15
2 5 8 12 19
3 6 9 16 22
10 13 14 17 
10

Output: 
0
*/

int main() {
    int r, c, n;
    cin >> r >> c;

    vector<vector<int>> matrix(r, vector<int>(c, 0));
    for (int ri = 0; ri < r; ri++) {
        for (int ci = 0; ci < c; ci++) {
            cin >> n;
            matrix[ri][ci] = n;
        }
    }

    int target;
    cin >> target;

    Solution sol;
    cout << sol.searchMatrix(matrix, target) << endl;
}