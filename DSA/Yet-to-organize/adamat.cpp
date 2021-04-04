/*
https://www.codechef.com/SEPT20B/problems/ADAMAT
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int N, ni;
	    cin >> N;
	    long int mat[N][N];
	    for(long int i = 0; i < N; i++) {
	        for(long int j = 0; j < N; j++) {
	            cin >> ni;
	            mat[i][j] = ni;
	        }
	    }
	    long int count = 0;
	    for(long int i = N-1; i >= 0; i--) {
	        if(mat[0][i] == N*i + 1 and count % 2 == 1)
	            continue;
	        else if(mat[i][0] == N*i + 1 and count % 2 == 0)
	            continue;
	        count++;
	    }
	    cout << count << endl;
	}
	return 0;
}
