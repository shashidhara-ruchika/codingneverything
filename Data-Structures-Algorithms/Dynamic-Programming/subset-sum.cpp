// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// https://www.youtube.com/watch?v=34l1kTIQCIA

/*
Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.


Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.
*/

//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(int N, int arr[], int sum){
        // code here 
        
        int rows = N + 1;
        int cols = sum + 1;
        
        vector<vector<bool>> sum_pos(N + 1, vector<bool> (sum + 1, false));
        
        // initialize 0th col as T, since no ele can be included for 0 sum
        for (int r = 0; r < rows; r++)
            sum_pos[r][0] = true;
            
        // initialize 0th row as F, since including no ele cant give sum > 0
        for (int c = 1; c < cols; c++)
            sum_pos[0][c] = false;

        // r denotes whether arr[r - 1] should be included or not
        // r - 1th ele, since indexing is 1, as 0 means including no elements    
        for (int r = 1; r < rows; r++) {
            
            // c denotes the sum that can be formed
            for (int c = 1; c < cols; c++) {
                
                // ele to be included or not included
                int ele = arr[r - 1];
                
                if (c < ele)
                    sum_pos[r][c] = sum_pos[r - 1][c];
                
                else
                    sum_pos[r][c] = sum_pos[r - 1][c] || sum_pos[r - 1][c - ele];
            }
        }
        
        return sum_pos[rows - 1][cols - 1];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(N, arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends