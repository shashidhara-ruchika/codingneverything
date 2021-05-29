/*
https://www.codechef.com/NOV20B/problems/ADADISH
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int adadish(vector<int>& dish, int N) {
        if (N == 0)
            return dish[0];
        else if (N == 1)
            return dish[1];
        else {
            int b1 = dish[N];
            int b2 = dish[N - 1];
            int i = N - 2;
            
            while (i > -1) {
                if (b1 < b2)
                    b1 += dish[i];
                else
                    b2 += dish[i];
                i--;
            }
            return max(b1, b2);
        }
    }
    
};

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    
	    int N;
	    cin >> N;
	    
	    int d;
	    vector<int> dish(N);
	    
	    for(int i = 0; i < N; i++) {
	        cin >> d;
	        dish[i] = d;
	    }
	    sort(dish.begin(), dish.end());
	    
	    Solution *soln = new Solution;
	    int mintime = soln -> adadish(dish, N - 1);
	    cout << mintime << endl;
	    
	}
	return 0;
}
