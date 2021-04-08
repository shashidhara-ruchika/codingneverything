/*
https://www.codechef.com/NOV20B/problems/FEMA2
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	
	queue<int> mag;
	queue<int> iron;
	    
	while(T--){
	    int n, k, i=0, j=0, count=0;
	    cin >> n >> k;
	    string s;
	    cin >> s;
	
	    for(int i=0; i<n; i++) {
	        
	        if(s[i]=='M')
	            mag.push(i);
	        
	        if(s[i]=='I')
	            iron.push(i);
	        
	        if(s[i]=='X' || i==n-1) {
	            
	            while(!mag.empty() && !iron.empty()) {
	                
	                int sheet=0, l=0, r=0;
	                l=min(mag.front(), iron.front());
	                r=max(mag.front(), iron.front());
	                
	                for(int q=l; q<=r; q++) {
	                    if(s[q]==':')
	                    sheet++;
	                }
	                
	                if((k + 1 - abs(l-r) - sheet) > 0) {
	                    count++;
	                    mag.pop();
	                    iron.pop();
	                }
	                
	                else if(mag.front() < iron.front())
	                    mag.pop();
	                
	                else
	                    iron.pop();   
	                
	            }
	            
	            while(!mag.empty())
	                mag.pop();
	            
	            while(!iron.empty())
	                iron.pop();
	        }
	    }
	    cout << count << endl;
	}
	return 0;
}
