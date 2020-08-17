/*
https://www.codechef.com/LRNDSA02/problems/CHFQUEUE
*/

/*
https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/

Let input sequence be 'arr[]' and size of array be 'n'

1) Create a new empty stack S

2) For every element 'arr[i]' in the input sequence 'arr[]',
   where 'i' goes from 0 to n-1.
    a) while S is nonempty and the top element of 
       S is greater than or equal to 'arr[i]':
           pop S
    
    b) if S is empty:
           'arr[i]' has no preceding smaller value
    c) else:
           the nearest smaller value to 'arr[i]' is 
           the top element of S

    d) push 'arr[i]' onto S
*/

#include <iostream> 
#include <bits/stdc++.h>

using namespace std; 

int main() 
{ 
	
	int n, k;
	cin >> n >> k;
	int arr[n];
	for(int i = 0; i < n; i++) 
	    cin >> arr[i];
	long long int f = 1;
	stack<pair<int, int>> st;
	for(int i = 0; i < n ; i++) {
	    int j = n - i - 1;
	    while(!st.empty() && st.top().first >= arr[j])
	        st.pop();
	    if(!st.empty()) {
	        f *= st.top().second - j + 1;
	        f %= 1000000007;
	    }
	    st.push(make_pair(arr[j], j));
	}
	cout << f << endl;
	return 0; 
} 
