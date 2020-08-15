/*
https://www.codechef.com/LRNDSA02/problems/NOTALLFL
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    int n,k;
	    cin >> n >> k;
	    
	    int a[n];
	    for(int i = 0; i < n; i++)
	        cin >> a[i];
	    
	    int cakes[k+1];
	    for(int i = 0; i <= k; i++)
	        cakes[i] = 0;
	    
	    int curr = 0, l = 0, ma = 0;
	    
	    for(int i = 0; i < n; i++) {
	        
	        if(cakes[a[i]] == 0)
	            curr++;
	            
	        cakes[a[i]]++;
	        
	        if(curr==k) {
	            ma = max(ma,i-l);
	            for(int j = l; j < n; j++) {
	                
	                cakes[a[j]]--;
	                
	                if(cakes[a[j]]==0) {
	                    l = j + 1;
	                    break;
	                }
	            }
	            curr--;
	        }
	    }
	    ma = max(ma,n-l);
	    cout << ma << endl;
	}
	return 0;
}
