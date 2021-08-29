/*
https://binarysearch.com/problems/Interval-Unoin
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int>& a, vector<int> &b) {
    if (a[0] < b[0])
        return true;
    else if (a[0] == b[0]){
        if (a[1] <= b[1])
            return true;
        else
            return false;
    }
    else
        return false;
}

vector<vector<int>> intervalUnion(vector<vector<int>>& intervals) {
    
    vector<vector<int>> ans;
    
    if (intervals.size() == 0)
        return ans;

    sort(intervals.begin(), intervals.end(), comp);
    
    int start = intervals[0][0];
    int end = intervals[0][1];    

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        }
        else {                    
            ans.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];            
        }
    }
    if (intervals[intervals.size() - 1][0] <= end) {
        ans.push_back({start, end});
    }

    return ans;
}

/*
Input
4
45 60
1 5
5 15
15 17
2 3

Output
1 15
15 17
45 60

*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    vector<vector<int>> d = intervalUnion(v);
    for (int i = 0; i < n; i++) {
        cout << v[i][0] << " " << v[i][1] << endl;
    }
    cout << endl;
    return 0;
}