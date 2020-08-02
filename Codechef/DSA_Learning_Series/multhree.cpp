/*
https://www.codechef.com/LRNDSA01/problems/MULTHREE
TLE
*/

/*
8  1  9  8  6  2  4  8  6  2  4  8  6
8  9 18 26 32 34 38 46 52 54 58 64 72

d2 = [    (d0 + d1)] mod 10
d3 = [2 * (d0 + d1)] mod 10
d4 = [4 * (d0 + d1)] mod 10
d5 = [8 * (d0 + d1)] mod 10
d6 = [16* (d0 + d1)] mod 10

2 mod 10 = 2
4 mod 10 = 4
8 mod 10 = 8
16 mod 10 = 6
32 mod 10 = 2
64 mod 10 = 4
128 mod 10 = 8
256 mod 10 = 6

5 mod 10 = 5
10 mod 10 = 0
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long long int K, d0, d1, d2, d3, dn, num_sum = 0;
	    cin >> K >> d0 >> d1;
	    /*num = d0 + d1;
	    num_sum = d0 + d1;
	    while(K-- > 2) {
	        num_sum += num;
	        num = num_sum % 10;
	    }
	    cout << num_sum << endl;*/
	    d2 = (d0 + d1) % 10;
	    d3 = (d0 + d1 + d2) % 10;
	    dn = d3;
	    cout << d0 << d1 << d2 << d3 << endl;
	    num_sum = d0 + d1 + d2 + d3;
	    if(d3 != 0) {
	        while(K-- > 4) {
	            if(dn == 2) {
	                num_sum += 4;
	                dn = 4;
	            }
	            else if(dn == 4) {
	                num_sum += 8;
	                dn = 8;
	            }
	            else if(dn == 8) {
	                num_sum += 6;
	                dn = 6;
	            }
	            else if(dn == 6) {
	                num_sum += 2;
	                dn = 2;
	            }
	        }
	    }
	    cout << num_sum << endl;
	    cout << endl;
	       
	}
	return 0;
}

