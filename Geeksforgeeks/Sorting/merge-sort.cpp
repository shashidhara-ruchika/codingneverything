/*
https://practice.geeksforgeeks.org/problems/merge-sort/1/
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int l_len = m - l + 1;                     
         int r_len = r - m;
         
         int l_arr[l_len];
         int r_arr[r_len];
         
         // copy left & right parts of arr to l_arr & r_arr
         for(int i = 0; i < l_len; i++) 
            l_arr[i] = arr[l + i];
         for(int j = 0; j < r_len; j++)
            r_arr[j] = arr[m + 1 + j];
            
         int l_ptr = 0;
         int r_ptr = 0;
         int arr_ptr = l;
         
         while (l_ptr < l_len && r_ptr < r_len) {
             
             if (l_arr[l_ptr] <= r_arr[r_ptr]) {
                 arr[arr_ptr] = l_arr[l_ptr];
                 l_ptr++;
             }
             else {
                 arr[arr_ptr] = r_arr[r_ptr];
                 r_ptr++;
             }
             
             arr_ptr++;
         }
         
         // copy remaining ele in l_arr
         while (l_ptr < l_len) {
             arr[arr_ptr] = l_arr[l_ptr];
             l_ptr++;
             arr_ptr++;
         }
         
         // copy remaining ele in r_arr
         while (r_ptr < r_len) {
             arr[arr_ptr] = r_arr[r_ptr];
             r_ptr++;
             arr_ptr++;
         }
         
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if (l >= r) {
            return;
        }
        
        int m = l + (r - l)/2;      // find mid len -> m
        mergeSort(arr, l, m);       // mergesort left arr
        mergeSort(arr, m + 1, r);   // mergesort right arr
        merge(arr, l, m, r);        // merge left & right arr
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends