/*
https://binarysearch.com/problems/Longest-Path-in-a-Graph
*/

/*
You are given a two-dimensional integer list graph representing 
an adjacency list where graph[i] contains a list of nodes i is connected to. 
Given that the graph is acyclic and directed, 
return the length of the longest path in the graph without repeated nodes.
*/

#include <bits/stdc++.h> 
using namespace std; 

class Graph {
    private:
        vector<vector<int>> graph;
        vector<int> visited;
        vector<int> dist;
        
    public:
        Graph();
        void dfs(int v);
        void reset_visited();
        int get_longest_path();
        void input_graph();
};

Graph :: Graph() {
    this -> input_graph();
    
    vector<int> v(graph.size(), 0);
    this -> visited = v;

    vector<int> d(graph.size() + 1, 0);
    this -> dist = d;    
}

void Graph :: input_graph() {
    int total_nodes;
    cin >> total_nodes;
    for(int i = 0; i < total_nodes; i++) {
        vector<int> v;
        this -> graph.push_back(v);
    }
    int lines, source, dest;
    cin >> lines;
    while(lines-- > 0) {
        cin >> source >> dest;
        this -> graph[source].push_back(dest);
    }
}

void Graph :: dfs(int v) {
    this -> visited[v] = 1;
    for (auto u : this -> graph[v]) {
        if (! this -> visited[u]) {
            this -> dfs(u);            
        }
        this -> dist[v] = max(this -> dist[v], this -> dist[u] + 1);
    }
    
}

void Graph :: reset_visited() {
    for(int i = 0; i < this -> visited.size(); i++)
        this -> visited[i] = 0;
}

int Graph :: get_longest_path() {
    
    //this -> reset_visited();

    for (int i = 0; i < this -> graph.size(); i++) {
        if (!this -> visited[i]) {
            this -> dfs(i);
        }
    }

    int max_dist = 1;
    for(auto d : this -> dist) {
        max_dist = max(max_dist, d);
    }

    return max_dist;
}

/*
Input
6 
8
0 1 
0 3
1 2 
1 5
2 4 
3 1 
3 4
4 5

Output
5

Explanation
We can take the path 0 -> 3 -> 1 -> 2 -> 4 -> 5 with length 5.
*/

int main() {
    Graph *g = new Graph();
    cout << g -> get_longest_path() << endl;
    return 0;
}

