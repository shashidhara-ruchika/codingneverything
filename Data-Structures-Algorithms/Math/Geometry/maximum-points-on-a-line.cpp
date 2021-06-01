/*
https://binarysearch.com/problems/Points-on-a-Line
*/

#include <bits/stdc++.h>

using namespace std;

int maxPointsOnSameLine(vector<vector<int>>& coordinates) {
    
    if(coordinates.size() == 0)
        return 0;
    
    if (coordinates.size() == 1)
        return 1;

    // y = slope * x + c
    // all values : point index from coordinates

    map< pair<double, double>, unordered_set<int> > other_pts;
    // key : pair(slope, c)

    unordered_map<int, unordered_set<int>> x_pts;
    // key : common x co-ord

    unordered_map<int, unordered_set<int>> y_pts;
    // key : common y co-ord

    unordered_map<double, unordered_set<int>> origin_pts;
    // key : slope 
        
    for(int p1 = 0; p1 < coordinates.size(); p1++) {
        
        for(int p2 = p1 + 1; p2 < coordinates.size(); p2++) {
            
            double x1 = coordinates[p1][0];
            double y1 = coordinates[p1][1];
            double x2 = coordinates[p2][0];
            double y2 = coordinates[p2][1];

            // lines passing through origin
            if (x1 == y1 && x2 == y2) {
                
                double slope = (y2 - y1) / (x2 - x1);
                
                if(origin_pts.find(slope) == origin_pts.end()) {
                    unordered_set<int> s;
                    origin_pts[slope] = s;
                }
                
                origin_pts[slope].insert(p1);
                origin_pts[slope].insert(p2);
            }

            // lines parallel to y-axis, cutting x-axis (common x co-ord)
            else if (x1 == x2) {
                
                if(x_pts.find(x1) == x_pts.end()) {
                    unordered_set<int> s;
                    x_pts[x1] = s;
                }
                
                x_pts[x1].insert(p1);
                x_pts[x1].insert(p2);
            }

            // lines parallel to x-axis, cutting y-axis (common y co-ord)
            else if (y1 == y2) {
                
                if(y_pts.find(y1) == y_pts.end()) {
                    unordered_set<int> s;
                    y_pts[y1] = s;
                }
                
                y_pts[y1].insert(p1);
                y_pts[y1].insert(p2);
            }

            // all other lines
            else {
                
                double slope = (y2 - y1) / (x2 - x1);
                double c = y1 - slope * x1;
                
                if(other_pts.find({slope, c}) == other_pts.end()) {
                    unordered_set<int> s;
                    other_pts[{slope, c}] = s;
                }
                
                other_pts[{slope, c}].insert(p1);
                other_pts[{slope, c}].insert(p2);
            }       

        }

    }
    
    int max_count = 0;

    for(auto it : origin_pts) {
        max_count = max(max_count, (int)it.second.size());
    }    

    for(auto it : x_pts) {
        max_count = max(max_count, (int)it.second.size());
    }
    
    for(auto it : y_pts)  {
        max_count = max(max_count, (int)it.second.size());
    }

    for(auto it : other_pts) {
        max_count = max(max_count, (int)it.second.size());
    }

    return max_count;
}

vector<vector<int>>& input_coord() {
    int lines, x, y;
    cin >> lines;
    vector<vector<int>> coord(lines, vector<int>(2, 0));
    for(int i = 0; i < lines; i++) {
        cin >> x >> y;
        coord[i][0] = x;
        coord[i][1] = y;
    }
    return coord;
}

/*
Input
7
5 1
7 2
9 3
0 0
1 1
5 5
6 6

Output
4
*/

int main() {
    vector<vector<int>> coord = input_coord();
    cout << maxPointsOnSameLine(coord) << endl;
    return 0;
}