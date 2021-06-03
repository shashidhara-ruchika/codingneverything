/*
https://binarysearch.com/problems/Inverse-Factorial
*/

#include <bits/stdc++.h>
using namespace std;

/*
The factorial of a number n is defined as n! = n * (n - 1) * (n - 2) * ... * 1.
Given a positive integer a, return n such that n! = a. 
If there is no integer n that is a factorial, then return -1.
*/

int factorialInverse(int a) {
    if(a < 2)
        return !a;
    if(a < 3)
        return a;
    
    int n = 1;
    for(int i = 2; i <= a; i++) {
        n *= i;
        if(n == a)
            return i;
    }
    return -1;
}

/*
Input
6

Output
3

Input
10

Output
-1
*/

int main() {
    int a;
    cin >> a;
    cout << factorialInverse(a) << endl;
    return 0;
}