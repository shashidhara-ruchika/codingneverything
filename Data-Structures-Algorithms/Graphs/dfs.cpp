// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution_rec {
  private:
    vector<int> dfspath;
    void dfs(int v, vector<int> adj[], vector<bool>& visited) {
        visited[v] = true;
        dfspath.push_back(v);
        for (auto &u : adj[v]) {
            if (!visited[u])
                dfs(u, adj, visited);
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        
        dfs(0, adj, visited);
        
        return this -> dfspath;
    }
    
};

// iterative using stack
class Solution {

public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<bool> vis(V, false);
        
        vector<int> dfsp;
        
        stack<int> stk;
        
        stk.push(0);
        
        while (!stk.empty()) {
            
            int v = stk.top();
            stk.pop();
            
            if (!vis[v]) {
                vis[v] = true;
                dfsp.push_back(v);
            }
            
            for (int vi = adj[v].size() - 1; vi >= 0; --vi) {
                //cout << v << " " << adj[v][vi] << endl;
                if (!vis[adj[v][vi]])
                    stk.push(adj[v][vi]);
            }
                
        }
        
        return dfsp;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
