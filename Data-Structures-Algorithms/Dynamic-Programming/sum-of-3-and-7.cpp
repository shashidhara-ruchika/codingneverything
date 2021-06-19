/*
https://binarysearch.com/problems/3-and-7
*/

#include<iostream>

using namespace std;

bool has3and7sum(int n) {
    if(n < 3)
        return false;
    if(n % 3 == 0 || n % 7 == 0)
        return true;
    if(has3and7sum(n - 3) || has3and7sum(n - 7))
        return true;
    return false;
}
/*
Input 
13
Output
1
*/

int main () {
    int n;
    cin >> n;
    cout << has3and7sum(n) << endl;
    return 0;
}