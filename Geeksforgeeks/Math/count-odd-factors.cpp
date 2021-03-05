/*
https://practice.geeksforgeeks.org/problems/count-odd-factors0844/1/
*/


// numbers which have odd number of factors are sq numbers or perfect numbers
// ex: 1, 4, 9, 16, 25, 36, etc.
// the number of sq numbers betwenn 1 & n is floor(sqrt(n))
// ex: sqrt(18) = 4.xxx, there are 4 numbers - 1, 4, 9, 16 , count = 4 between 1 & 18

#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int count(int N){
        // code here
        return floor(sqrt(N));
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.count(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends

