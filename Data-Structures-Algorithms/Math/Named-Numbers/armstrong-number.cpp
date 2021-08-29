// https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1#

// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        
        int sum = 0;
        
        int num = n;
        
        while (num > 0) {
            sum += (int)pow(num % 10, 3);
            num /= 10;
        }
        
        if (sum == n)
            return "Yes";
        else
            return "No";
    }
};

/*
153
*/

/*
Yes
*/

/*
1^3 + 5^3 + 3^3 = 3 + 125 + 27 = 153
*/

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends