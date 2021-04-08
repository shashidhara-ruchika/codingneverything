/*
https://www.codechef.com/OCT20B/problems/CVDRUN
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    int N, K, X, Y;
	    cin >> N >> K >> X >> Y;
	    int visited[N];
	    for(int i = 0; i < N; i++) 
	        visited[i] = 0;
	    bool infected = false;
	    while(visited[X] != 1) {
	        visited[X] = 1;
	        if(X == Y) {
	            infected = true;
	            break;
	        }
	        X = (X + K) % N;
	    }
	    if(infected)  
	        cout << "YES\n";
	    else
	        cout << "NO\n";
	}
	return 0;
}
