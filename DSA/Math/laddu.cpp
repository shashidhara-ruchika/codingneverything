/*
https://www.codechef.com/LRNDSA01/problems/LADDU
*/

/*
CONTEST_WON > 20
laddus += 300
CONTEST_WON <= 20
laddus += 320
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int N, laddus = 0, rs;
	    string origin;
	    cin >> N >> origin;
	    while(N-- > 0) {
	        string activity;
	        cin >> activity;
	        if(activity == "CONTEST_WON") {
	            cin >> rs;
	            laddus += 300;
	            if(rs <= 20) 
	                laddus += 20 - rs;
	        }
	        else if(activity == "TOP_CONTRIBUTOR") {
	            laddus += 300;
	        }
	        else if(activity == "BUG_FOUND") {
	            cin >> rs;
	            laddus += rs;
	        }
	        else if(activity == "CONTEST_HOSTED"){
	            laddus += 50;
	        }
	    }
	    //cout << laddus << endl;
	    if(origin == "INDIAN")
	        cout << (long int)(laddus/200) << endl;
	    else
	        cout << (long int)(laddus/400) << endl;
	}
	return 0;
}
