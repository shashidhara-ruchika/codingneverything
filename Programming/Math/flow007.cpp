/*
https://www.codechef.com/LRNDSA01/problems/FLOW007
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int reverse_num(int num) {
    int rev_num = 0;
    while(num != 0) {
        rev_num = (10 * rev_num) + (num % 10);
        num = num/10;
    }
    return rev_num;
}

int main() {
	int t;
	cin >> t;
	for(int ti = 0; ti < t; ti++) {
	    //string num;
	    int num;
	    cin >> num;
	    /* 
        //Don't try reversing number as string directly
        //trailing zeroes will appear in the begining eg: 2300 - 0032
        string copy_num(num);
	    reverse(copy_num.begin(), copy_num.end());
	    cout << num << "\t" << copy_num << endl;
	    cout << copy_num << endl;
        */
	    cout << reverse_num(num) << endl;
	}
	return 0;
}
