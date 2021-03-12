/*
https://leetcode.com/problems/valid-square/
*/

# include <bits/stdc++.h>

using namespace std;

// Given the coordinates of four points in 2D space, return whether the four points could construct a square.
// Input points are given in no order
// A square has 4 equal sides & 2 equal diagnals.
// Angles between adjacent sides & between intersecting diagonals is 90 deg

class Solution {
public:   
    
    int map_dist(vector<int>& p1, vector<int>& p2) {
        
        int ds = ((p1[0] - p2[0]) * (p1[0] - p2[0])) + ((p1[1] - p2[1]) * (p1[1] - p2[1]));
        return ds;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        
        // find the distance between each point, num of distances = 4(sides) + 2(diagonals)
        
        vector<int> dist_sq;
        
        dist_sq.push_back(map_dist(p1, p2));
        dist_sq.push_back(map_dist(p1, p3));
        dist_sq.push_back(map_dist(p1, p4));
        dist_sq.push_back(map_dist(p2, p3));
        dist_sq.push_back(map_dist(p2, p4));
        dist_sq.push_back(map_dist(p3, p4));  
        
        sort(dist_sq.begin(), dist_sq.end());
            
        return (dist_sq[0] > 0            // > 0 for all
                && dist_sq[0]==dist_sq[3] // first 4 equal
                && dist_sq[4]==dist_sq[5] // longest 2 (diagnal) equal
                && dist_sq[3]<dist_sq[4]);        
    }

    vector<int> input2DPoint() {
        vector<int> point2d(2);
        int n1, n2;
        cin >> n1 >> n2;
        point2d[0] = n1;
        point2d[1] = n2;
        return point2d;
    }
};

int main() {

    /*
    1 1 
    0 0
    1 0
    0 1
    */

    /*
    1
    */

    Solution *soln = new Solution;
    vector<int> p1, p2, p3, p4;
    p1 = soln -> input2DPoint();
    p2 = soln -> input2DPoint();
    p3 = soln -> input2DPoint();
    p4 = soln -> input2DPoint();

    cout << soln -> validSquare(p1, p2, p3, p4);

    return 0;
}