/*
https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#
*/

 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    // Your code goes here
	    int s_len = s.length();
	    
	    if (s_len < 2)
	        return 0;
	        
	    int prefix_suffix_len = 0;
	    int i = 1;
	    
	    while (i < s_len) {
	        
	        if (s[i] == s[prefix_suffix_len]) {
	            prefix_suffix_len++;
	            i++;
	        }
	        else {
	            i -= prefix_suffix_len - 1;
	            prefix_suffix_len = 0;
	        }
	    }
	    
	    return prefix_suffix_len;
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
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends


/*
p -> prefix_suffix_len
i -> i

a b c a b c
p i

a b c a b c
p   i

a b c a b c
p     i

a b c a b c
  p     i

a b c a b c
    p     i

p = 3
*/
