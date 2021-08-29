/*
https://binarysearch.com/problems/Interval-Duration
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


int intervalDuration(vector<vector<int>>& intervals) {

    if (intervals.size() == 0)
        return 0;

    sort(intervals.begin(), intervals.end(), comp);
    
    int start = intervals[0][0];
    int end = intervals[0][1];
    int count = 0;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= end) {
            end = max(end, intervals[i][1]);
        }
        else {              
            count += end - start + 1;          
            start = intervals[i][0];
            end = intervals[i][1];            
        }
    }
    if (intervals[intervals.size() - 1][0] <= end) {
        count += end - start + 1;
    }
    
    return count;
}

/*
Input
4
45 60
1 5
5 15
2 3

Output
31

Explanation
The total unique covered distance is 
[45, 60] (duration of 16) and [1 ,15] (duration of 15).
*/

int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    cout << intervalDuration(v) << endl;
    return 0;
}