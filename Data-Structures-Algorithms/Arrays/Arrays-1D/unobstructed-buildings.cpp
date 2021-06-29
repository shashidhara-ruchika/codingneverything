/*
https://binarysearch.com/problems/Unobstructed-Buildings
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> indexes_of_unobstructed_buildings(vector<int>& heights) {
    
    vector<int> building_indexes;
    
    if (heights.size() == 0)
        return building_indexes;

    building_indexes.insert(building_indexes.begin(), (int)heights.size() - 1);
    int curr_max_height = heights[(int)heights.size() - 1];

    for (int i = heights.size() - 2; i >= 0; i--) {
        if (heights[i] > curr_max_height) {
            building_indexes.insert(building_indexes.begin(), i);
            curr_max_height = heights[i];
        }
    }

    return building_indexes;

}

/*
Example 1

Input
5
1 5 5 2 3

Output
2 4

Explanation
We can see the ocean in building heights[2] and heights[4].

Example 2

Input
5
5 4 3 2 1

Output
0 1 2 3 4

Explanation
We can see the ocean in every building since 
each building is taller than every other on its right.

Example 3

Input
5
1 1 1 1 1

Output
4

Explanation
We can't see the ocean in any building other than the last one.
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> indexes = indexes_of_unobstructed_buildings(v);
    for (auto &i : indexes) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
