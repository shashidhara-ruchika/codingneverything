/*
https://www.codechef.com/LRNDSA02/problems/ZCO12001
*/

/*
when 1 occurs, 1 is pushed into the stack &
when 0 occurs, an ele is popped from the stack

when the stack size is high, that is the maximum depth, and its index is recorded as depth_in,

close_pos denote when the stack is empty i.e. the end mark of a well-bracketed sequence
the prev_close_pos and next_close_pos are recorded
when their diff (i.e. count of that particular well-bracketed sequence) is maximum, 
    prev_close_pos + 1 is the mark of the start of that particular well-bracketed sequence
*/    

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long int N;
	cin >> N;
	int ip, depth_in, max_depth = 0, i = 1, prev_close_pos = 0, new_close_pos, count_in, max_count = 0;
	stack<int> stck;
	while(i <= N) {
	    cin >> ip;
	    if(ip == 1) {
	        stck.push(1);
	        if(stck.size() > max_depth) {
	            //cout << i << " " << stck.size() << endl;
	            depth_in = i;
	            max_depth = stck.size();
	        }
	    }
	    else {
	        stck.pop();
	        if(stck.empty()) {
	            new_close_pos = i;
	            if(new_close_pos - prev_close_pos > max_count) {
	                max_count = new_close_pos - prev_close_pos;
	                count_in = prev_close_pos + 1;
	            }
	            prev_close_pos = new_close_pos;
	        }
	    }
	    i++;
	}
	cout << max_depth << " " << depth_in << " " << max_count << " " << count_in << endl;
	return 0;
}
