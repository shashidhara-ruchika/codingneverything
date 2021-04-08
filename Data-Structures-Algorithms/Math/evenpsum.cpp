/*
https://www.codechef.com/DEC20B/problems/EVENPSUM
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int a, b, eps, ae, ao, be, bo;
	    cin >> a >> b;
	    ae = a / 2;
	    ao = a - ae;
	    be = b / 2;
	    bo = b - be;
	    eps = (ae*be + ao*bo);
	    cout << eps << endl;
	}
	return 0;
}
