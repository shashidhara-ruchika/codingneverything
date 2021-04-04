/*
https://practice.geeksforgeeks.org/problems/ffd66b6a0bf7cefb9987fa455974b6ea5695709e/1/#
*/

#include <bits/stdc++.h>
using namespace std;

int find_height(int tree[], int n, int k);
int woodCollected(int tree[], int n, int h);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n;

        int tree[n];
        for(int i=0; i<n; i++)
            cin>>tree[i];
        cin>>k;

        cout<< find_height(tree,n,k) << endl;
    }
    return 1;
}// } Driver Code Ends


int woodCollected(int tree[], int n, int h) 
{
    int woodTotal = 0;
    for (int i = n - 1; i >= 0; i--) 
    {
        if (tree[i] - h <= 0)    
            break;
        woodTotal += tree[i] - h;
    }
    return woodTotal;
}


int find_height(int tree[], int n, int k)
{
    sort(tree, tree + n);
    
    // low - min cut of tree that can be made = 0
    // high - max cut of tree that can be made = height of tallest tree
    int low = 0, high = tree[n - 1];
    
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        int collected = woodCollected(tree, n, mid);
        
        if (collected == k)
            return mid;
        
        else if (collected > k)
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    
    return -1;
    
}
