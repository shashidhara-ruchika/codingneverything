/*
https://www.codechef.com/LRNDSA02/problems/STFOOD
*/

// check order of input -  S P V

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int N, S, V, P, max1 = 0, max_profit;
	    cin >> N;
	    while(N-- > 0) {
	        cin >> S >> P >> V;
	        max_profit = floor( P / (S + 1) ) * V;
	        if(max_profit  > max1) {
	            max1 = max_profit;
	        }
	    }
	    cout << max1 << endl;
	}
	return 0;
}
