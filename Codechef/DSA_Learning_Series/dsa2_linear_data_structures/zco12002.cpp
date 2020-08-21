/*
https://www.codechef.com/LRNDSA02/problems/ZCO12002
*/


/*
v   2   4   14  25
w         13  21
(15, 21) can be taken between v:14 - w:21, time taken = 21-14+1 = 8
(5, 10)  can be taken between v:4  - w:13, time taken = 13- 4+1 = 10
(7, 25)  cannot be taken as we cannot go back from any w after time 25 

sort v & w in ascending order
latest arrival time = startt = upper bound search on v
earliest leave time = endt   = lower bound search on w
time taken = earliest arrival time - latest arrival time + 1
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long int n, x, y, s, e, t, mint = INT_MAX;
	cin >> n >> x >> y;
	vector<long int> v;
	vector<long int> w;
	vector<pair<long int, long int>> se;
	for(int i = 0; i < n; i++) {
	    cin >> s >> e;
	    se.push_back(make_pair(s, e));
	}
	for(int i = 0; i < x; i++) {
	    cin >> t;
	    v.push_back(t);
	}
	for(int i = 0; i < y; i++) {
	    cin >> t;
	    w.push_back(t);
	}
	sort(v.begin(), v.end());
	sort(w.begin(), w.end());
	for(auto x: se) {
	    //cout << x.first << " " << x.second << endl;
	    long int endt = -1, startt = 0;     
        // lower bound returns first pointer (0) if not found
        // upper bound returns last  pointer (y) if not found 
	    startt = upper_bound(v.begin(), v.end(), x.first) - v.begin();
	    endt = lower_bound(w.begin(), w.end(), x.second) - w.begin();
	    //cout << startt << " " << endt << endl;
	    if(startt > 0 && endt < y) {
	        mint = min(mint, w[endt] - v[startt - 1] + 1);
	    }
	}
	cout << mint << endl;
	return 0;
}
