/*
https://www.codechef.com/AUG20B/problems/CRDGAME3
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int pc, pr, fc, fr;
	    cin >> pc >> pr;
	    fc = ceil(pc/9.0);
	    fr = ceil(pr/9.0);
	    //cout << fc << " " << fr << endl;
	    if(fc < fr) {
	        cout << "0 " << fc << endl;
	    }
	    else {
	        cout << "1 " << fr << endl;
	    }
	    //cout << endl;
	       
	}
	return 0;
}
