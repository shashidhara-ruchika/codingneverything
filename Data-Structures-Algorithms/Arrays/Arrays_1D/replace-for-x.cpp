/*
https://www.codechef.com/OCT20B/problems/REPLESX
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
	int T;
	cin >> T;
	
	while(T-- > 0) {
	    
	    long int n, x, p, k, ip;
	    cin >> n >> x >> p >> k;
	    long int a1[n], a[n + 5];
	    
	    for(long int i = 0; i < n; i++) 
	        cin >> a1[i];
	    sort(a1, a1 + n);
	    
	    for(long int i = 0; i < n; i++) 
	        a[i + 1] = a1[i];
	    
	    if(a[p] == x) {
	        cout << "0\n";
	        continue;
	    }
	        
	    long int count = 0;
	    
	    if (k > p) {
	        if (a[p] < x) {
	            cout << "-1\n";
	            continue;
	        }
	        while (a[p] > x && p >= 1) {
	            p--;
	            count++;
	        }
	    }
	    
	    else if (k < p) {
	        if (a[p] > x) {
	            cout << "-1\n";
	            continue;
	        }
	        while (a[p] < x && p <= n) {
	            p++;
	            count++;
	        }
	    }
	    
	    else {
	        
	        if (a[p] > x) {
    	        while (a[p] > x && p >= 1) {
    	            p--;
    	            count++;
    	        }
	        }
	    
    	    else {
    	        while (a[p] < x && p <= n) {
    	            p++;
    	            count++;
    	        }
    	    }
	        
	    }
	    
	    cout << count << endl;
	       
	}
	return 0;
}
