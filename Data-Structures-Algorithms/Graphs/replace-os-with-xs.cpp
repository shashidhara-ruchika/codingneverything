// https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1/

/*
Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’.
Replace all ‘O’ with ‘X’ that are surrounded by ‘X’.
A ‘O’ (or a set of ‘O’) is considered to be by surrounded by ‘X’ 
if there are ‘X’ at locations just below, just above, just left and just right of it.
*/

/*
Input: n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: ans = {{'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'X', 'X'}, 
               {'X', 'X', 'O', 'O'}}
Explanation: Following the rule the above 
matrix is the resultant matrix. 
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        int matrow = mat.size();
        int matcol = mat[0].size();
        
        vector<vector<bool>> visited(matrow, vector<bool>(matcol, false));
        
                            //u, d, r, l
        vector<int> dirrow = {0, 0, 1, -1}; 
        vector<int> dircol = {1, -1, 0, 0};
        
        // perform bfs on O on edges(bprder cells) of matrix to mark Os as visited
        queue<pair<int, int>> qnoto;
        
        for (int c = 0; c < matcol; ++c) {
            if (mat[0][c] == 'O')
                qnoto.push({0, c});
            if (mat[matrow - 1][c] == 'O')
                qnoto.push({matrow - 1, c});
        }
        
        for (int r = 1; r < matrow - 1; ++r) {
            if (mat[r][0] == 'O')
                qnoto.push({r, 0});
            if (mat[r][matcol - 1] == 'O')
                qnoto.push({r, matcol - 1});
        }
        
        while(!qnoto.empty()) {
            int curr_r = qnoto.front().first;
            int curr_c = qnoto.front().second;
            
            qnoto.pop();
            
            visited[curr_r][curr_c] = true;
            
            for (int i = 0; i < 4; ++i) {
                int new_r = curr_r + dirrow[i];
                int new_c = curr_c + dircol[i];
                
                if (new_r >= 0 && new_r < matrow &&
                    new_c >= 0 && new_c < matcol &&
                    mat[new_r][new_c] == 'O' &&
                    !visited[new_r][new_c])
                        qnoto.push({new_r, new_c});
            }
            
        }
        
        // for all Os that are not marked as visited, replace them with Xs
        for (int r = 1; r < matrow - 1; ++r) {
            for (int c = 1; c < matcol - 1; ++c) {
                
                if (mat[r][c] == 'O' && !visited[r][c])
                    mat[r][c] = 'X';
                
            }
        }
        
        return mat;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends