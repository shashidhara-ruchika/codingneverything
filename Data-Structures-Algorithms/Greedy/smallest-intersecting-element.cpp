/*
https://binarysearch.com/problems/Smallest-Intersecting-Element
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    if (p1.first < p2.first)
        return true;
    else if (p1.first == p2.first) 
        return p1.second <= p2.second;
    else
        return false;
}

void reset_rows(vector<int> &rows) {
    for(int i = 0; i < rows.size(); i++)
        rows[i] = 0;
}

bool check_rows1(vector<int>& rows) {
    for(int i = 0; i < rows.size(); i++) {
        if (rows[i] == 0)
            return false;
        cout << rows[i] << " ";
    }
    return true;
}

int smallestIntersectingElement(vector<vector<int>>& matrix) {

    if (matrix.size() == 0)
        return -1;

    vector<pair<int, int>> all_vals;

    for (int r = 0; r < matrix.size(); r++) {
        for (auto &num : matrix[r]) {
            all_vals.push_back({num, r});
        }
    }

    sort(all_vals.begin(), all_vals.end(), comp);

    int count = 0;
    vector<int> rows(matrix.size(), 0);

    for (int i = 0; i < all_vals.size(); i++) {
        if (i == 0 || all_vals[i].first != all_vals[i - 1].first) {
            count = 1;
            reset_rows(rows);
            rows[all_vals[i].second] = 1;
        }
        else {
            count++;
            rows[all_vals[i].second] = 1;
        }
        if (count >= matrix.size()) {
            cout << count << endl;
            cout << check_rows1(rows) << " check rows\n"; 
            if (check_rows1(rows) == 1)
                return all_vals[i].first;
        }
    }
    
    return -1;
}
/*
Input
3 3
1 2 4
4 9 9
0 2 4

Output
4

Input
2 2
1 3
0 0

Output
-1
*/

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    cout << smallestIntersectingElement(v) << endl;
    return 0;
}