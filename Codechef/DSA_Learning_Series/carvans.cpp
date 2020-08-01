/*
https://www.codechef.com/LRNDSA01/problems/CARVANS
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    int N;
	    cin >> N;
	    
	    int cf, cb, count = 1;
	    cin >> cf;
	    N--;
	    while(N-- > 0) {
	        cin >> cb;
	        //cout << cf << " " << cb << endl;
	        if(cb <= cf) {
	            cf = cb;
	            count++;
	        }
	    }
	    cout << count << endl;
	}
	return 0;
}
