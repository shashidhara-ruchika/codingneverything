/*
https://leetcode.com/problems/minimum-height-trees/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // traverse from leaf nodes to the centre
    // add all the leaf(child) nodes in a queue
    // traverse child one by one and check for their neighbours and push it to the queue
    // repeat till < 2 nodes remain

    // edges don't make a cyclic graph so path from anywhere becomes a tree

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {        
        
        if(n == 1)
            return {0};       
        
        // adjacency graph
        vector<vector<int>> graph(n);
        
        // degree of each node/vertex v
        vector<int> degree(n, 0);
        
        // from input edge, build adj graph & update degree of each vertex
        for ( vector<int> edge: edges ) {
            
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            
            degree[edge[0]]++;
            degree[edge[1]]++;
            
        } 
        
        // solve by topological sorting (child to root)
        
        // first append all child nodes to queue
        queue<int> q;
        for (int i = 0; i < n; i++)    {
            if (degree[i] == 1)
                q.push(i);
        }
        
        // unitl > 2 vertices remain in the queue
        while (n > 2) {
            
            int size_q = q.size();
            n -= size_q;
            
            for (int i = 0; i < size_q; i++) {
                
                // get the child vertex
                int child = q.front();
                q.pop();
                
                for (int j = 0; j < graph[child].size(); j++) {
                    
                    // decrease the child vertex degree & push its single parent vertex
                    degree[graph[child][j]]--;
                    if (degree[graph[child][j]] == 1)
                        q.push(graph[child][j]);
                    
                }
            }
            
        }
        
        // for all the vertices that remin in the queue (1 or 2 vertices)
        // pop it and add it to the ans min height vertex vector array
        vector<int> minheight_v;
        while (!q.empty()) {
            minheight_v.push_back(q.front());
            q.pop();
        }
        
        return minheight_v;
    }

    vector<vector<int>> inputEdges() {
        
        int num_edges;
        cin >> num_edges;

        vector<vector<int>> edges;

        int v1, v2;
        while(num_edges-- > 0) {

            cin >> v1 >> v2;

            vector<int> edge;
            edge.push_back(v1);
            edge.push_back(v2);

            edges.push_back(edge);
        }

        return edges;
    }

    void displayArr(vector<int>& root_v) {
        for ( auto v: root_v ) 
            cout << v << " ";
        cout << endl;
    }
};

/*
6
5
[[3,0],[3,1],[3,2],[3,4],[5,4]]
*/

int main() {

    /*
    6
    5
    3 0
    3 1
    3 2
    3 4
    5 4
    */

    /*
    3 4
    */

    Solution *soln = new Solution;
    
    int n;
    cin >> n;

    vector<vector<int>> edges = soln -> inputEdges();

    vector<int> min_height_root_nodes = soln -> findMinHeightTrees(n, edges);

    soln -> displayArr(min_height_root_nodes);

    return 0;
    
}
