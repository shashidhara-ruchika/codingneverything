/*
https://www.codechef.com/LRNDSA01/problems/FCTRL
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int N;
	    cin >> N;
	    long int div5 = 0, ci;
        ci = N;
        while(ci > 0) {
            //cout << ci << endl;
            div5 += ci/5;
            ci /= 5;
        }
	    cout << div5 << endl;
	}
	return 0;
}
