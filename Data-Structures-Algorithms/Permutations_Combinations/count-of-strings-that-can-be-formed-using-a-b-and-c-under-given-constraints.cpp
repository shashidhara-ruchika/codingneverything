// https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints1135/0/

/*
Given a length n, count the number of strings of length n 
that can be made using ‘a’, ‘b’ and ‘c’ with 
at-most one ‘b’ and 
at-most two ‘c’s allowed.

Example 1:

Input: n = 1
Output: 3
Explanation: Possible strings are: "a",
"b" and "c"

Example 2:

Input: n = 3
Output: 19
Explanation: Number of strings with 3 
occurrances of a: 1
2-a and 1-b: 3
2-a and 1-c: 3
1-a, 1-b and 1-c: 6
1-a and 2-c: 3
1-b and 2-c: 3
So, total number of strings of length 3
is 1 + 3 + 3 + 6 + 3 + 3 = 19
*/

#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    // b c    no. of ways

    // 0 0 => 1

    // 0 1 => n

    // 0 2 => nC2

    // 1 0 => n

    // 1 1 => n(n-1)

    // 1 2 => (n)* (n-1)C2

    return  1 + 
            2*n + 
            (n - 1) * n * (n + 1) / 2;
}