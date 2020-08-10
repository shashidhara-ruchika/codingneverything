/*
https://www.codechef.com/LRNDSA02/problems/PSHOT
*/

/* 
Denote team B’s current score by C(B), team A’s current score by C(A), 
team A’s remaining shots by R(A), team B’s remaining shots by R(B). 
At any point, team A is winning iff (C(A) - C(B)) > R(B). 
The inverse is true for B winning.
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
	    string s;
	    cin >> s;
	    //cout << s << endl;
	    long int str_len = s.length(), ca = 0, cb = 0, ra, rb, i;
	    for(i = 1; i <= str_len; i++) {
	        if(s[i-1] == '1') {
    	        if(i % 2 == 1)  // odd pos, A shoots
    	                ca += 1;
    	        else       // even pos, B shoots
    	                cb += 1;
	        }
	        ra = str_len/2 - ceil(i/2.0);
	        rb = str_len/2 - floor(i/2.0);
	        //cout << ca << " " << cb << " " << ra << " " << rb << endl;
	        if(ca - cb > rb) {
	            cout << i << endl;
	            break;
	        }
	        else if(cb - ca > ra) {
	            cout << i << endl;
	            break;
	        }
	        else if(i == str_len) {
	            cout << str_len << endl;
	            break;
	        }
	    }
	}
	return 0;
}
