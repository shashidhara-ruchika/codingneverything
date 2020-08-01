/*
https://www.codechef.com/LRNDSA01/problems/LAPIN/
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    string str;
	    cin >> str;
	    int str_len = str.length();
	    
	    unordered_map<char, int> l_str;
	    unordered_map<char, int> r_str;
	    
	    for(int i = 0; i < str_len/2; i++) {
	        if(l_str.find(str[i]) == l_str.end()) 
	            l_str.insert(make_pair(str[i], 1));
	        else
	            l_str[str[i]]++;
	    }
	    
	    for(int i = ceil(str_len/2.0); i < str_len; i++) {
	        if(r_str.find(str[i]) == r_str.end()) 
	            r_str.insert(make_pair(str[i], 1));
	        else
	            r_str[str[i]]++;
	    }
	    
	    /*for(auto x : l_str)
	        cout << x.first << " " << x.second << endl;
        cout << endl;
        
        for(auto x : r_str)
	        cout << x.first << " " << x.second << endl;
        cout << endl;*/
        
        if(l_str == r_str)
            cout << "YES\n";
        else
            cout << "NO\n";
	    
	}
	return 0;
}
