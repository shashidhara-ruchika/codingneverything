/*
https://leetcode.com/problems/pascals-triangle/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> genNextRow(vector<int> &prev_row) {
        
        vector<int> curr_row;
        curr_row.push_back(1);
        
        int len = prev_row.size();
        for (int i = 0; i < len - 1; i++) 
            curr_row.push_back(prev_row[i] + prev_row[i + 1]);
        curr_row.push_back(1);
        
        return curr_row;
    }
    
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> pascalst;
        
        if (numRows == 0)
            return pascalst;
        
        if (numRows == 1) {
            pascalst = {{1}};
            return pascalst;
        }
        
        pascalst = {{1}, {1, 1}};    
        
        int i = 2;        
        while (i < numRows) {
            pascalst.push_back(genNextRow(pascalst[i-1]));
            i++;
        }
        return pascalst;
        
    }

    void solve() {
        int n;
        cin >> n;
        vector<vector<int>> pascals_triangle = generate(n);

        for(int i = 0; i < pascals_triangle.size(); i++) {
            for(int j = 0; j < pascals_triangle[i].size(); j++) {
                cout << pascals_triangle[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    /*
    5
    */
    
    /*
    1
    1 1
    1 2 1
    1 3 3 1
    1 4 6 4 1
    */

    Solution soln;
    soln.solve();

    return 0;
}