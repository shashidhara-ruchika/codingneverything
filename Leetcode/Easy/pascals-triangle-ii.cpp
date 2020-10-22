/*
https://leetcode.com/problems/pascals-triangle/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> row = {1};        
        if (rowIndex == 0)
            return row;
        
        row.push_back(1);        
        if (rowIndex == 1)
            return row;
        
        // row = {1, 1}
        
        int i = 2, j, prev, next;
        while (i <= rowIndex) {
            j = 0;
            prev = row[0];
            while(j < row.size() - 1) {
                next = row[j + 1];
                row[j + 1] = prev + next;
                prev = next;
                j++;
            }
            row.push_back(1);
            i++;
        }
        return row;
    }

    void solve() {
        int n;
        cin >> n;
        vector<int> pascals_rowi = getRow(n);

        for(int i = 0; i < pascals_rowi.size(); i++)
            cout << pascals_rowi[i] << " ";
        cout << endl;
    }
};

int main() {

    /*
    5
    */
    
    /*
    1 5 10 10 5 1
    */

    Solution soln;
    soln.solve();

    return 0;
}