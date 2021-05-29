/*
https://www.codechef.com/LRNDSA03/problems/EXUNC
*/

// AC for 7 test cases, WA for 1 test case pts - 30/100

/*
types of q:
1 ai x
change a at index i
update si at indexes i, i+1

2 si
print the first ele of si subarray i.e. upper bound of si
*/

/*
here indexing starts from 1, so it should be taken care
store a vector & whenver new subarray is formed, store its index in s set
this happens during first ip of a & whenever query is 1
if query is 2, return the lower bound of si by counting the number os 1s till index i in si
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long int n, q, ai, aend;
	cin >> n >> q;
	vector<long int> a;
	set<long int> s;
	cin >> ai;
	a.push_back(ai);
	aend = ai;
	s.insert(1);
	for(long int i = 2; i < n+1; i++) {
        cin >> ai;
        if(ai % aend != 0)
            s.insert(i);
        a.push_back(ai);
        aend = ai;
	}
	long int qi, x, si, oldai;
	while(q--) {
	    cin >> qi;
	    if(qi == 1) {
	        cin >> ai >> x;
	        auto abegin = a.begin();
	        auto ain = abegin + ai;
	        auto ainbefore = ain - 1;
	        auto ainafter = ain + 1;
	        oldai = *ain;
	        *ain = x;
	        if(ai > 1) {
	            if(x % *ainbefore != 0 )
	                s.insert(ai);
	            else if(x % *ainbefore == 0 )
	                s.erase(ai);
	        }
	        if(ai < n) {
	            if(*ainafter % x != 0 )
	                s.insert(ai + 1);
	            else if(*ainafter % x == 0)
	                s.erase(ai + 1);
	        }
	    }
	    if(qi == 2) {
	        cin >> si;
	        auto sit = s.upper_bound(si);
	        sit--;
	        cout << *sit << endl;
	    }
	}
	return 0;
}


