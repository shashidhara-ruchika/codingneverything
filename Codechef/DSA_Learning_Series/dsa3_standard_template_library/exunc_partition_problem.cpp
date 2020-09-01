/*
https://www.codechef.com/LRNDSA03/problems/EXUNC
*/

// TLE

/*
types of q:
1 ai x
change a at index i
update si at indexes i, i+1

2 si
print the first ele of si subarray i.e. lower bound of si
*/

/*
here indexing starts from 1, so it should be taken care
store a & s= {0} as vectors
whenver a new subarray is formed at index i, s[i] = 1, this happens during first ip of a & whenever query is 1
if query is 2, return the lower bound of si by counting the number os 1s till index i in si
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//void printas(vector<long int> &a, vector<long int> &s);

int main() {
	long int n, q, ai, aend;
	cin >> n >> q;
	vector<long int> a;
	vector<long int> s;
	cin >> ai;
	a.push_back(ai);
	aend = ai;
	s.push_back(1);
	for(long int i = 2; i < n+1; i++) {
        cin >> ai;
        if(ai % aend != 0) {
            s.push_back(1);
        }
        else {
            s.push_back(0);
        }
        a.push_back(ai);
        aend = ai;
	}
	//printas(a, s);
	//cout << endl;	    
    long int qi, x, si;	    
    for(long int qit = 0; qit < q; qit++) {
        cin >> qi;
        if(qi == 1) {
            cin >> ai >> x;
            //cout << ai << " " << x << endl;
            auto abegin = a.begin();
            auto sbegin = s.begin();
            auto acurr = abegin + ai - 1;
            auto scurr = sbegin + ai - 1;
            *(acurr) = x;
            if(ai == 1) {
                *(scurr) = 1;
                if(*(acurr + 1) % *acurr != 0) 
                    *(scurr + 1) = 1;
                else
                    *(scurr + 1) = 0;
            }
            else if(ai == n) {
                if(*(acurr) % *(acurr - 1) != 0)
                    *(scurr) = 1;
            }
            else {
                if(*(acurr) % *(acurr - 1) != 0 && *(acurr) % *(acurr + 1) == 0) {
                    *(scurr) = 1;
                    *(scurr + 1) = 0;
                }
                else if (*(acurr) % *(acurr - 1) == 0 && *(acurr) % *(acurr + 1) != 0) {
                    *(scurr) = 0;
                    *(scurr + 1) = 1;
                }
                else if (*(acurr) % *(acurr - 1) != 0 && *(acurr) % *(acurr + 1) != 0) {
                    *(scurr) = 1;
                    *(scurr + 1) = 1;
                }
                else {
                    *(scurr) = 0;
                    *(scurr + 1) = 0;
                }
            }
            //printas(a, s);
            //cout << endl;
        }
        if(qi == 2) {
            cin >> si;    
            //cout << si << endl;
            long int sinew;
            auto sbegin = s.begin();
            for(long int sit = 0; sit < si; sit++) {
                if(*(sbegin + sit) == 1)
                    sinew = sit + 1;
            }
            cout << sinew << endl;
        }
    }
    //cout << endl;	    
	return 0;
}

/*
void printas(vector<long int> &a, vector<long int> &s) {
    for(auto x: a)
	    cout << x << " ";
	cout << endl;
	for(auto x: s)
	    cout << x << " ";
    cout << endl;
}
*/

