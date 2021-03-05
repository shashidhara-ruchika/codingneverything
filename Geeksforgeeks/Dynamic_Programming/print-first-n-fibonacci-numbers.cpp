/*
https://practice.geeksforgeeks.org/problems/print-first-n-fibonacci-numbers1002/1/
*/


//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;
vector<long long> printFibb(int);

int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        
        //calling function printFibb()
        vector<long long> ans = printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}
// } Driver Code Ends


//User function template for C++

// n : given integer value
// print the nth fibb number in the function 
vector<long long> printFibb(int n) {
    //code here
    
    vector<long long> fibnum(n);
    
    int i = 0;
    while (i < n) {
        
        if (i == 0 || i == 1) 
            fibnum[i] = 1;
        
        else 
            fibnum[i] = fibnum[i - 1] + fibnum[i - 2];
        
        i++;    
    }
    return fibnum;   
}