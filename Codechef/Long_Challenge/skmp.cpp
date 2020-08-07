/*
https://www.codechef.com/AUG20B/problems/SKMP
*/

// WA

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    string s;
	    string p;
	    cin >> s >> p;
	    //cout << s << endl;
	    map<char, long int> sarr;
	    for(auto x : s) {
	        if(sarr.find(x) == sarr.end()) 
	            sarr.insert(make_pair(x, 1));
	        else
	            sarr[x]++;
	    }
	    /*for(auto x : sarr)
	        cout << x.first << " " << x.second << endl;
	    cout << endl;*/
	    for(auto x : p) {
	        sarr[x]--;
	    }
	    for(auto x : sarr) {
	        cout << string(x.second, x.first);
	        if(x.first == p[0])
	            cout << p;
	    }
	    cout << endl;
	}
	return 0;
}
