/*
https://www.codechef.com/LRNDSA01/problems/CONFLIP
*/

/*
I = 1
H H H H H  --> T H T H T
H = 2, T = 3

I = 2
T T T T T  --> H T H T H
H = 3, T = 2

I = 1
H H H H  --> H T H T
H = 2, T = 2

I = 2
T T T T  --> T H T H
H = 2, T = 2

I   Q   Val
1   1   floor(N/2.0)
1   2   ceil(N/2.0)
2   1   ceil(N/2.0)
2   2   floor(N/2.0)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int G;
	    cin >> G;
	    while(G-- > 0) {
	        long long int I, N, Q;
	        cin >> I;
	        cin >> N;
	        cin >> Q;
	        //cout << N/2.0 << endl;
	        if(I == Q)
	            cout << (long long int)(floor(N/2.0)) << endl;
	        else
	            cout << (long long int)(ceil(N/2.0)) << endl;
	        //cout << endl;
	    }
	       
	}
	return 0;
}
