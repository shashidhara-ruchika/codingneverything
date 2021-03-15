/*
https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x0849/1#
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    int firstOccurence(vector<long long> v, int n, int x, int low, int high) {
        
        if (high >= low) {
            
            int mid = low + (high - low) / 2;
            
            if ( (mid == 0 || x > v[mid - 1]) && v[mid] == x)
                return mid;
            
            else if (x > v[mid])
                return firstOccurence(v, n, x, mid + 1, high);
            
            else
                return firstOccurence(v, n, x, low, mid - 1);
        }
        
        return -1;
    }
    
    int lastOccurence(vector<long long> v, int n, int x, int low, int high) {
        
        if (high >= low) {
            
            int mid = low + (high - low) / 2;
            
            if ( (mid == n - 1 || x < v[mid + 1]) && v[mid] == x)
                return mid;
            
            else if (x >= v[mid])
                return lastOccurence(v, n, x, mid + 1, high);
            
            else
                return lastOccurence(v, n, x, low, mid - 1);
        }
        
        return -1;
    }
    
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        int n = v.size();
        int first = firstOccurence(v, n, x, 0, n - 1);
        int last  = lastOccurence(v, n, x, 0, n - 1);
        
        if (first == -1 || last == -1)
            return {-1, -1};
        
        return {first, last};
    }
};

// { Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}
  // } Driver Code Ends