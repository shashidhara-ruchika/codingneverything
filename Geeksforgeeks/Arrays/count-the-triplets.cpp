/*
https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1
*/

#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    sort(arr, arr + n);
	    
	    int sum_ptr, left_ptr, right_ptr;
	    int count = 0;
	    
	    // traverse from last ele to first ele for the  sum value (c)
	    for (int sum_ptr = n - 1; sum_ptr >= 0; sum_ptr--) {
	        
	        left_ptr = 0;
	        right_ptr = sum_ptr - 1;
	        
	        while (left_ptr < right_ptr && left_ptr < sum_ptr && right_ptr > 0) {
	            
	            //cout << arr[left_ptr] << " " << arr[right_ptr] << " " << arr[sum_ptr] << endl;
	            
	            // triplet(a, b, c) found where a + b = c
	            if(arr[left_ptr] + arr[right_ptr] == arr[sum_ptr]) {
	                count++;
	                left_ptr++;
	                right_ptr--;
	            }
	             
	            // if a + b < c, inc ptr of a(smaller num on the left)
	            else if (arr[left_ptr] + arr[right_ptr] < arr[sum_ptr])
	                left_ptr++;
	            
	            // if a + b > c, dec ptr of b(larger num on the right)
	            else
	                right_ptr--;
	        }
	        
	    }
	    
	    return count;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends