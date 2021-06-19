/*
https://binarysearch.com/problems/Mutual-Followers
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> mutualFollowers(vector<vector<int>>& relations) {
    set<pair<int, int>> rel;
    set<int> s;
    for(auto &r : relations) {
        int small, big;
        if(r[0] < r[1]) {
            small = r[0];
            big = r[1];
        }
        else {
            small = r[1];
            big = r[0];
        }
        pair<int, int> p = {small, big};
        if(rel.count(p) == 0)
            rel.insert(p);
        else {
            s.insert(small);
            s.insert(big);
        }
    }
    vector<int> v(s.begin(), s.end());
    sort(v.begin(), v.end());
    return v;
}

vector<vector<int>>& input_vec() {
    int row, col;
    cin >> row >> col;
    vector<vector<int>> v(row, vector<int>(col, 0));
    for(int r = 0; r < row; r++) {
        for(int c = 0; c < col; c++) {
            cin >> v[r][c];
        }
    }
    return v;
}

void print_vec(vector<int>& v) {
    for(int r = 0; r < v.size(); r++) {
        cout << v[r]<< " ";
    }
    cout << endl;
}

/*
Input
6
0 1
1 2
2 3
3 4
2 1
1 0

Output
0 1 2
*/

int main() {
    vector<vector<int>> v = input_vec();
    vector<int> f = mutualFollowers(v);
    print_vec(f);
    return 0;
}