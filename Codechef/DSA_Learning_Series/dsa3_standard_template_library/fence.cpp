/*
https://www.codechef.com/LRNDSA03/problems/FENCE
*/

// RE for 70% of cases

/*
initialized set of pairs of (row, col) for k plant cells, count = 0

.   .   .   .   .   .
.   .   .   .   x   .
.   x   x   x   .   .
.   x   .   x   .   .
.   x   x   x   .   .
.   .   .   .   .   .

checked if each top, right, bottom, left pairs were present in the set,
if they were not present, incremented counter

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int n, m, k, r, c, count = 0, i, j;
	    cin >> n >> m >> k;
	    set<pair<long long int, long long int>> f;
	    for(i = 0; i < k; i++) {
	        cin >> r >> c;
	        f.insert(make_pair(r,c));
	    }
	    for(auto it : f) {
	        r = it.first;
	        c = it.second;
	        // top
	        if(f.find(make_pair(r-1, c)) == f.end())
	            count++;
	        // right
	        if(f.find(make_pair(r, c-1)) == f.end())
	            count++;
	        // bottom
            if(f.find(make_pair(r+1, c)) == f.end())
	            count++;
	        // left
            if(f.find(make_pair(r, c-1)) == f.end())
	            count++;          
	    }
	    cout << count << endl;
	}
	return 0;
}
