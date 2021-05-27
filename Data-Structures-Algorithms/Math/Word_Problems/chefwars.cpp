/*
https://www.codechef.com/AUG20B/problems/CHEFWARS
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int H, P;
	    cin >> H >> P;
	    while(1) {
	        H = H - P;
	        P = floor(P/2);
	        if(H <= 0) {
	            cout << "1\n";
	            break;
	        }
	        if(P <= 0) {
	            cout << "0\n";
	            break;
	        }   
	    }
	       
	}
	return 0;
}
