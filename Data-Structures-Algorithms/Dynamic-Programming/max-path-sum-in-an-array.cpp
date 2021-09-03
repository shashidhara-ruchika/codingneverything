// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#

/*
Given a NxN matrix of positive integers. 
There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 
return the largest sum of any of the paths up to row N-1.
*/

/*
Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.
*/

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> cost(Matrix.size(), vector<int>(Matrix[0].size(), 0));
        
        // initialize cell costs
        for (int r = 0; r < cost.size(); r++) {
            for (int c = 0; c < cost[0].size(); c++)
                cost[r][c] = Matrix[r][c];
        }
        
        vector<int> col_mov = {-1, 0, 1};
        
        for (int r = 1; r < Matrix.size(); r++) {
            
            for (int c = 0; c < Matrix[0].size(); c++) {
                
                vector<int> pos_col_moves(3, c);
                pos_col_moves[0] = c - 1;
                pos_col_moves[2] = c + 1;
                
                int max_val = 0;
                for (auto p : pos_col_moves) {
                    if (p >= 0 && p < Matrix[0].size())
                        max_val = max(cost[r - 1][p], max_val);
                }
                
                cost[r][c] += max_val;
                
            }
        }
        
        int max_path_sum = cost[Matrix.size() - 1][0];
        for (int c = 1; c < cost[0].size(); c++)
            max_path_sum = max(cost[Matrix.size() - 1][c], max_path_sum);
            
        return max_path_sum;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends