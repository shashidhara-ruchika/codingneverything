/*
https://www.codechef.com/AUG20B/problems/LINCHESS
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int N, K, P, min1 = 9999999999, minp = -1;
	    cin >> N >> K;
	    while(N -- > 0) {
	        cin >> P;
	        if(K % P == 0 && K / P <= min1)  {
	            min1 = K / P;
	            minp = P;
	        }
	    }
	    cout << minp << endl;
	       
	}
	return 0;
}
