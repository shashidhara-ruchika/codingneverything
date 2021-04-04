/*
https://www.codechef.com/SEPT20B/problems/TREE2
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int n, ai;
		cin >> n;
		set<long long int> a;
		int zeroflag=0;
		for(long long int i = 0; i < n; i++)
		{
			cin >> ai;
			if(ai == 0) 
			    zeroflag=1;
			a.insert(ai);
		}
		cout << a.size() - zeroflag << endl;
	}
	return 0;
}
