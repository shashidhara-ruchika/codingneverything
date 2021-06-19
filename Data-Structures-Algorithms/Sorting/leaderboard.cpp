/*
https://binarysearch.com/problems/Leaderboard
*/

#include <bits/stdc++.h>
using namespace std;

bool static comp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second >= b.second) 
        return true;        
    return false;
}

vector<int> getleaderboard(vector<int>& nums) {
    
    vector<pair<int, int>> indexed_matches(nums.size(), {0, 0}); //index, matches_won
    for(int im = 0; im < nums.size(); im++) {
        indexed_matches[im].first = im;
        indexed_matches[im].second = nums[im];
    }

    sort(indexed_matches.begin(), indexed_matches.end(), comp);

    vector<int> leaderboard(nums.size(), 0);

    for (int im = 1; im < indexed_matches.size(); im++) {
        if (indexed_matches[im].second == indexed_matches[im - 1].second)
            leaderboard[indexed_matches[im].first] = leaderboard[indexed_matches[im - 1].first];
        else 
            leaderboard[indexed_matches[im].first] = leaderboard[indexed_matches[im - 1].first] + 1;
    }

    return leaderboard;    
}

/*
Input
5
50 30 50 90 10

Output
1 2 1 0 3
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    vector<int> lb = getleaderboard(v);

    for(auto &l : lb)
        cout << l << " ";
    cout << endl;

    return 0;
}