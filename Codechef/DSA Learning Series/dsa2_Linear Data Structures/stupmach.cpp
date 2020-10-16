/*
https://www.codechef.com/LRNDSA02/problems/STUPMACH
*/

// max capacity = min (si, prev_min) 

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int N, si, min1 = 9999999999, count = 0;
	    cin >> N;
	    while(N-- > 0) {
	        cin >> si;
	        //cout << si << endl;
	        min1 = min(si, min1);
	        count += min1;
	    }
	    cout << count << endl;
	       
	}
	return 0;
}
