/*
https://binarysearch.com/problems/Distributed-Systems
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> make_adj_list(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> adj_list(n);
    for(int i = 0; i < n; i++) {
        vector<pair<int, int>> v;
        adj_list.push_back(v);
    }
    for(auto &v : edges) {
        adj_list[v[0]].push_back({v[1], v[2]});
        adj_list[v[1]].push_back({v[0], v[2]});
    }
    return adj_list;
}

void dfs(int v, vector<vector<pair<int, int>>>& adj_list, vector<int>& time_taken) {
    for(auto up : adj_list[v]) {           
        int new_time = time_taken[v] + up.second;
        if (new_time < time_taken[up.first]) {
            time_taken[up.first] = new_time;
            dfs(up.first, adj_list, time_taken);                 
        }                      
    }        
}

int findMaxTime(int n, vector<vector<int>>& edges) {
    n = n + 1;
    vector<vector<pair<int, int>>> adj_list = make_adj_list(n, edges);
    vector<int> time_taken(n, 10000000);
    time_taken[0] = 0;
    for(int i = 0; i < n; i++) 
        dfs(i, adj_list, time_taken);    
    return *max_element(time_taken.begin(), time_taken.end());
}

vector<vector<int>>& input_edges() {
    int no_edges, source, dest, weight;
    cin >> no_edges;
    vector<vector<int>> edges;
    while(no_edges-- > 0) {
        cin >> source >> dest >> weight;
        edges.push_back({source, dest, weight});
    }
    return edges;
}

/*
Input
3
3
0 1 2
1 2 3
2 3 1

Output
6

Explanation
Node 3 receives the message from 0 -> 1 -> 2 -> 3 which takes 2 + 3 + 1 = 6 time.
*/

int main() {
    int total_nodes;
    cin >> total_nodes;
    vector<vector<int>> edges = input_edges();
    cout << findMaxTime(total_nodes, edges) << endl;
    return 0;
}