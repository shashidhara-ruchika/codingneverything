/*
https://binarysearch.com/problems/First-Fit-Room
*/

#include <bits/stdc++.h>
using namespace std;

int ret_first_fit_room(vector<int>& rooms, int target) {
    for(int i = 0; i < rooms.size(); i++) {
        if(rooms[i] >= target)
            return rooms[i];
    }
    return -1;
}

/*
Example 1
Input
5
15 10 30 50 15
20

Output
30

Explanation
30 is the first room that's at least as large as 20.

Example 2
Input
5
15 10 30 50 15
51

Output
-1

Explanation
There's no room that's at least 51.
*/

int main() {
    int n, target;
    cin >> n;
    vector<int> v(n, 0);
    for(int i =0; i < n; i++) 
        cin >> v[i];
    cin >> target;

    cout << ret_first_fit_room(v, target) << endl;

    return 0;
}