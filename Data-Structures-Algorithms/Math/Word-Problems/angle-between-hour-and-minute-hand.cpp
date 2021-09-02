// https://practice.geeksforgeeks.org/problems/angle-between-hour-and-minute-hand0545/1#

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int getAngle(int H , int M) {
        // code here
        /*
        float m = M * 6.0;
        
        float h = M * 0.5 + (H % 12) * 30.0;
        
        h += (H != 12) ? H * 30.0 : 0.0;
        
        float diff = abs(h - m);
        
        return min(floor(diff), floor(360 - diff));
        */
        
        float diff = abs( ( (H % 12) * 30 ) - ( M * 5.5 ) );
        
        return min( floor(diff) , floor(360 - diff) );
        
        
        
    }
};


/*
12 30
*/

/*
165
*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int H,M;
        
        cin>>H>>M;

        Solution ob;
        cout << ob.getAngle(H,M) << endl;
    }
    return 0;
}  // } Driver Code Ends