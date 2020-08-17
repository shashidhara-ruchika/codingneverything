/*
https://www.codechef.com/LRNDSA02/problems/COMPILER
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    string lg;
	    cin >> lg;
	    long int len = 0, str_len = lg.length(), i = 0;
	    stack<char> s;
	    while(i < str_len) {
            if(lg[i] == '<')
                s.push('<');
            else {
                if(s.empty()) 
                    break;
                else { 
                    s.pop();
                    if(s.empty()) {
                        len = i + 1;
                    }
                }    
            }  
            i++;
	    }

	    cout << len << endl;  
	}
	return 0;
}
