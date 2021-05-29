/*
https://www.codechef.com/DEC20B/problems/VACCINE2
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mindays(vector<int> a, int d) {
    int mind = 0, prisk = 0, pok = 0;
    for (auto x : a) {
        if (x <= 9 or x >= 80)
            prisk++;
        else
            pok++;
    }
    mind += ceil(prisk * 1.0 / d) + ceil(pok * 1.0 / d);
    
    return mind;
}

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    
	    int N, D;
	    cin >> N >> D;
	    vector<int> a(N);
	    for (int i = 0; i < N; i++) {
	        cin >> a[i];
	    }
	    
	    if (D == 1)
	        cout << N << endl;
	    else 
	        cout << mindays(a, D) << endl;
	}
	return 0;
}
