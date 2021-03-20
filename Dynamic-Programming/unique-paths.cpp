/*
https://leetcode.com/problems/unique-paths/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    int uniquePaths(int m, int n) {
        
        // no of unique paths = (m + n - 2) C (m - 1) = (m + n - 2)! / (m - 1)! (n - 1)!
        
        unsigned long long paths = 1;
        
        for (unsigned long long i = n; i < m + n - 1; i++) {                     
            paths *= i;                                                                
            paths /= (i - (n - 1)); 
        } 
        
        return paths;
    }
    
    int uniquePaths_dp(int m, int n) {
        
        vector<vector<int>> path_table(m, vector<int> (n, 0));
        
        for (int r = 0; r < m; r++) {
            
            for (int c = 0; c < n; c++) {
                
                if (r == 0 || c == 0)
                    path_table[r][c] = 1;
                
                else
                    path_table[r][c] = path_table[r - 1][c] + path_table[r][c - 1];        
            }
        }
        
        return path_table[m - 1][n - 1];
    }
};

int main() {
    
    /*
    3 7
    13 17
    */

    /*
    28
    30421755
    */

    Solution *soln = new Solution();
    Solution *soln_dp = new Solution();

    int m1, n1;
    cin >> m1 >> n1;    
    cout << soln -> uniquePaths(m1, n1) << endl;

    int m2, n2;
    cin >> m2 >> n2;
    cout << soln -> uniquePaths_dp(m2, n2) << endl;

    return 0;
}