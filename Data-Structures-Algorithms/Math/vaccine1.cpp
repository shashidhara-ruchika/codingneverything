/*
https://www.codechef.com/DEC20B/problems/VACCINE1
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	int d1, v1, d2, v2, p, d = 0, tot = 0;
	cin >> d1 >> v1 >> d2 >> v2 >> p;
	
	while (tot < p) {
	    d++;
	    if (d >= d1)
	        tot += v1;
	    if (d >= d2)
	        tot += v2;
	    //cout << tot << " " << d << endl;
	}
	
	cout << d << endl;
	
	return 0;
}
