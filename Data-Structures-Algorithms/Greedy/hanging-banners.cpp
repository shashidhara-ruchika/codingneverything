/*
https://binarysearch.com/problems/Hanging-Banners
*/

#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:
You are given a list of list of integers intervals of the form [start, end] 
representing the starts and end points of banners you want to hang. 
Each banner needs at least one pin to stay up, 
and one pin can hang multiple banners. 
Return the smallest number of pins required to hang all the banners.

Note: The endpoints are inclusive, so if two banners are touching, 
e.g. [1, 3] and [3, 5], you can put a pin at 3 to hang both of them.

Intuition:
We have to hang every banner, 
so for each banner there must be an pin whose position 
is between banner[i][0] and banner[i][1] inclusively. 
We will sort the vector of banners by their ending position. 
Then we make sure that we take care of each banner in order.

Implementation:
So what position should we pick each time? 
We should pick as to the right as possible, because since banners are sorted, 
this gives you the best chance to pin down more banners. 
Therefore the position should always be banner[i][1] for the i_th banner.

This is exactly what we do in the for loop: 
check how many banners we can pin down with 
one pin aiming at the ending position of the current banner. 
Then we skip all these banners and start again from the next one 
(or the leftmost remaining one) that needs another pin.

Example:
banners = [[7,10], [1,5], [3,6], [2,4], [1,4]]

After sorting, it becomes:
banners = [[2,4], [1,4], [1,5], [3,6], [7,10]]

So first of all, we pin at position 4, we go through the array and 
see that all first 4 banners can be taken care of by this single pin. 
Then we need another pin for one last balloon. 
So the result should be 2.
*/

// Test Cases
//[[1, 4],[4, 5],[7, 9],[9, 12]]
//[[2,3],[0,0]]
//[[2,4],[0,3],[1,1]]
//[[0,3],[1,3],[2,5]]

bool comp(vector<int>& p1, vector<int>& p2) {
    return p1[1] < p2[1];
}

int minPins(vector<vector<int>>& intervals) {
    
    if(intervals.size() < 2)
        return intervals.size();

    sort(intervals.begin(), intervals.end(), comp);

    int pin_count = 1;
    int max_index = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] > max_index) {
            pin_count++;
            max_index = max(intervals[i][1], max_index);
        }
    }   
    
    return pin_count;
}

/*
Input
4
1 4
4 5
7 9 
9 12

Output:
2
*/

int main() {
    int n, n1, n2;
    vector<vector<int>> banners(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        cin >> n1 >> n2;
        banners[i][0] = n1;
        banners[i][1] = n2;
    }
    cout << minPins(banners) << endl;
    return 0;
}


