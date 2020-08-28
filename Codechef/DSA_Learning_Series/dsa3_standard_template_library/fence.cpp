/*
https://www.codechef.com/LRNDSA03/problems/FENCE
*/

// RE for 70% of cases

/*
initialized f[n+2][m+2] = 0 to remove edge cases at border cells, count = 0

.   .   .   .   .   .
.   .   .   .   x   .
.   x   x   x   .   .
.   x   .   x   .   .
.   x   x   x   .   .
.   .   .   .   .   .

checked for 1 cell whether top, right, bottom cells were each without 1, incremented count

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
	    long long int f[n+2][m+2];
	    for(i = 0; i < n+2; i++) {
	        for(j = 0; j < m+2; j++)
	            f[i][j] = 0;
	    }
	    for(i = 0; i < k; i++) {
	        cin >> r >> c;
	        f[r][c] = 1;
	    }
	    /*for(long int i = 0; i < n+2; i++) {
	        for(int j = 0; j < m+2; j++)
	            cout << f[i][j] << " ";
	        cout << endl;
	    }
	    cout << endl;*/
	    for(i = 1; i < n+1; i++) {
	        for(j = 1; j < m+1; j++) {
	            if(f[i][j] == 1) {
    	            // top
    	            if(f[i-1][j] != 1)
    	                count++;
    	            // right
    	            if(f[i][j+1] != 1)
    	                count++;
    	            // bottom
    	            if(f[i+1][j] != 1)
    	                count++;
    	            // left
    	            if(f[i][j-1] != 1)
    	                count++;
	            }
	        }
	           
	    }
	    cout << count << endl;
	}
	return 0;
}
