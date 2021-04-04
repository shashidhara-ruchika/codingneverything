/*
https://practice.geeksforgeeks.org/problems/activity-selection-1587115620/1#
*/

#include <bits/stdc++.h>

using namespace std;

class Solution{
    public:
    
    static bool sortbysecond(const pair<int, int> &a, const pair<int, int> &b) {
        return a.second < b.second;
    }
    
    int activitySelection(vector<int> start, vector<int> end, int n){
        
        vector<pair<int, int>> se_times;
        
        for (int i = 0; i < n; i++) {
            se_times.push_back({start[i], end[i]});
        }
        
        sort(se_times.begin(), se_times.end(), sortbysecond);
        
        //int new_start = se_times[0];
        int new_end = se_times[0].second;
        int total_activities = 1;
        
        for (int i = 1; i < n; i++) {
            
            if (se_times[i].first > new_end) {
                total_activities++;
                new_end = se_times[i].second;
            }
        }
        
        return total_activities;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends