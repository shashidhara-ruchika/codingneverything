// https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1/

/*
An image is represented by a 2-D array of integers, 
each integer representing the pixel value of the image.
Given a coordinate (sr, sc) representing the starting pixel (row and column) 
of the flood fill, and a pixel value newColor, "flood fill" the image.
To perform a "flood fill", consider the starting pixel, plus 
any pixels connected 4-directionally to the starting pixel of the same color 
as the starting pixel, plus any pixels connected 4-directionally to those pixels 
(also with the same color as the starting pixel), and so on. 
Replace the color of all of the aforementioned pixels with the newColor.
*/

/*
Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.

Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
*/

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        
        vector<vector<bool>> visited(image.size(), vector<bool> (image[0].size(), false));
        
        vector<int> dir_row = {0, 0, 1, -1};
        vector<int> dir_col = {1, -1, 0, 0};
        
        while (!q.empty()) {
            pair<int, int> curr_cord = q.front();
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int new_row = curr_cord.first + dir_row[i];
                int new_col = curr_cord.second + dir_col[i];
                
                if (new_row >= 0 && new_row < image.size() &&
                    new_col >= 0 && new_col < image[0].size() &&
                    !visited[curr_cord.first][curr_cord.second] &&
                    image[new_row][new_col] == image[curr_cord.first][curr_cord.second]
                    ) {
                        q.push({new_row, new_col});
                    }
            }
            
            image[curr_cord.first][curr_cord.second] = newColor;
            visited[curr_cord.first][curr_cord.second] = true;

        }
        
        
        return image;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends