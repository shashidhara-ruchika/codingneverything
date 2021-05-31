/*
https://binarysearch.com/problems/FizzBuzz
*/

#include <bits/stdc++.h>
using namespace std;


void printFizzBuzz(int n) {
    for (int i = 1; i <= n; i++) {
        stringstream s;
        if (i % 3 == 0)
            s << "Fizz";
        if (i % 5 == 0)
            s << "Buzz";
        if(i % 3 && i % 5)
            cout << i << " ";
        else
            cout << s.str() << " ";
    }
    cout << endl;
}
/*
Input
20

Output
1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz
*/

int main() {
    int n;
    cin >> n;
    printFizzBuzz(n);
    return 0;
}