/*
https://www.codechef.com/LRNDSA03/problems/SAVKONO
*/

/*
To find the min num of attacks, hits to Pain should be max
So the soilder i with highest Ai should attack
Ai can be the top of a priority queue, DS pq can store the Ai strengths
Attacks on Z(Pain) should happen until Z <= 0
At each iteration, Z = Z - Ai & Ai = floor(Ai/2.0) is performed
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    long int n, z, ai, amax, count = 0;
	    cin >> n >> z;
	    priority_queue<long int> pq;
	    for(int i = 0; i < n; i++) {
            cin >> ai;
            pq.push(ai);
	    }
	    while(pq.size() > 0) {
	        count++;
	        amax = pq.top();
	        //cout << amax << " " << z << endl;
	        pq.pop();
	        z = z - amax;
	        if(z <= 0) {
	            break;
	        }
	        amax = floor(amax/2.0);
	        if(amax > 0) {
	            pq.push(amax);
	        }
	    }
	    if(z <= 0)
	        cout << count << endl;   
        else
            cout << "Evacuate\n";
	}
	return 0;
}
