/*
https://binarysearch.com/problems/No-New-Friends
*/

#include <bits/stdc++.h>

using namespace std;

// Check if all nodes are connected
class Solution {
    private:
        int total_people;
        vector<vector<int>> friends;

    public:
        void input_total_people();
        void input_graph();
        bool solve();

};

void Solution :: input_total_people() {
    int n;
    cin >> n;
    total_people = n;
}

void Solution :: input_graph() {
    int n, n1, n2;
    while(n-- > 0) {
        vector<int> nodes(2, 0);
        cin >> n1 >> n2;
        nodes[0] = n1;
        nodes[1] = n2;
        friends.push_back(nodes);
    }   
}

bool Solution :: solve() {
    int n = total_people;
    vector<int> is_present(n, 0);
    for(int f = 0; f < friends.size(); f++)
    {
        is_present[friends[f][0]] = 1;
        is_present[friends[f][1]] = 1;
    }
    for (auto it: is_present)
    {
        if(it == 0)
            return false;
    }
    return true;
}

/*
Input
3 2
0 1 
1 2

Output
true

Explanation
Person 0 is friends with 1
Person 1 is friends with 0 and 2
Person 2 is friends with 1.
*/

int main() {
    Solution *soln = new Solution();
    soln -> input_total_people();
    soln -> input_graph();
    cout << soln -> solve() << endl;
    return 0;
}