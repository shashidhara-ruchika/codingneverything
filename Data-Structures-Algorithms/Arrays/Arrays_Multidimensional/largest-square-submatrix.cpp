/*
https://www.geeksforgeeks.org/maximum-size-sub-matrix-with-all-1s-in-a-binary-matrix/
https://binarysearch.com/problems/Largest-Square-Submatrix
*/

#include <bits/stdc++.h> 
using namespace std; 

class Solution
{
    public:
        vector<vector<int>> matrix;
        int check_square(int row, int col);
        int solve();
        void input_matrix();
};

/*
Input
6 7
0 0 0 0 0 1 1
0 0 0 0 0 1 1
1 1 1 1 0 0 0
1 1 1 1 0 0 0
1 1 1 1 0 0 0
1 1 1 1 0 0 0

Output
16

Explanation
The bottom left square has a bigger area than the top right square.
*/

int main()
{
    Solution *soln = new Solution;
    soln -> input_matrix();
    cout << soln -> solve() << endl;

    return 0;
}

void Solution :: input_matrix() {
    int row, col, num;
    cin >> row >> col;
    for(int r = 0; r < row; r++) {
        vector<int> v(col, 0);
        for(int c = 0; c < col; c++) {
            cin >> num;
            v[c] = num;
        }
        matrix.push_back(v);
    }
}

int Solution :: solve() {
    
    int max_area = 0;

    for (int row = 0; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {                       
            if (matrix[row][col] == 0)
                continue;
            max_area = max(max_area, check_square(row, col));     
        }
    }
    return max_area;
}

int Solution :: check_square(int row, int col)
{
    int r = row;
    int c = col;
    int valid = 1;
    while (r < matrix.size() && c < matrix[0].size() && matrix[r][c] == 1)
    {           

        for (int tr = r; tr >= row; tr--)
        {
            if (matrix[tr][c] == 0)
            {
                valid = 0;
                break;
            }
        }

        for (int tc = c; tc >= col; tc--)
        {
            if (matrix[r][tc] == 0)
            {
                valid = 0;
                break;
            }                
        }
        if (valid == 0)
            break;
        r++;
        c++;
    }
    
    //printf("%d %d %d %d %d\n", r, c, row, col, (r - row) * (c - col));
    return (r - row) * (c - col);
}