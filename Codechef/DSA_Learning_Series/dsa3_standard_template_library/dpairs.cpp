/*
https://www.codechef.com/LRNDSA03/problems/DPAIRS
*/

/*
Chef has two integer sequences A1,A2,…,AN and B1,B2,…,BM. 
You should choose N+M−1 pairs, each in the form (Ax,By), such that the sums Ax+By are all pairwise distinct.

Ex: 
A - 1 2 3       n = 3
B - 1 2 3 4     m = 4
Total pairs to be printed = n + m - 1 = 6

Count:           1       2       3       4       5       6
Sums:            2       3       4       5       6       7
All Pairs:      1,1     1,2     1,3     1,4                     // 1 is the min of A
                        2,1     2,2     2,3     2,4
                                3,1     3,2     3,3     3,4     // 4 is the max of B
Final:          Amin,B0 Amin,B1 Amin,B2 Amin,B3 A1,Bmax A2,Bmax
Final:          1,1     1,2     1,3     1,4     2,4     3,4
                        
Output only contains indexes, so no need to store all the values
We can just store min of A and its index & max of B and its index
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long int n, m, n_min_index, n_min = INT_MAX, m_max_index, m_max = INT_MIN, an, bm;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
	    cin >> an;
	    if(an < n_min) {
	        n_min = an;
	        n_min_index = i;
	    }
	}
	for(int i = 0; i < m; i++) {
	    cin >> bm;
	    if(bm > m_max) {
	        m_max = bm;
	        m_max_index = i;
	    }
	}
	for(int i = 0; i < m; i++) {
	    cout << n_min_index << " " << i << endl;
	}
	for(int i = 0; i < n; i++) {
	    if(i != n_min_index)
	        cout << i << " " << m_max_index << endl;
	}
	
	return 0;
}
