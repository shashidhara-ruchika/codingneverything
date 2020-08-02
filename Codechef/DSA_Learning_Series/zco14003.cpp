/*
https://www.codechef.com/LRNDSA01/problems/ZCO14003
*/

/*
budget of customers: 40, 3, 65, 33, 21
task: set a price say P such that P <= every customer's budget and maximize P

suppose we set:

If P = 40, customers with budget of 40, 65 will buy for 40
Then total revenue = 40 + 40 = 80

If P = 3, customers with budget of 40, 3, 65, 33, 21 will buy for 3
Then total revenue = 3 + 3 + 3 + 3 + 3 = 15

.
.
.

If P = 33, customers with budget of 40, 65, 33 will buy for 33
Then total revenue = 33 + 33 + 33 = 99 (This is the maximum possible value for P)
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    
    long int N, ni = 0, num;
    cin >> N;
    
    vector<long int> budget;
    vector<long int> revenue;
    
    while(ni++ < N) {
        cin >> num;
        budget.push_back(num);
    }
    sort(budget.begin(), budget.end());
    
    long int i = N;
    for(auto x : budget) {
        revenue.push_back(x * i--);
    }
    
    /*for(auto x : budget) {
        cout << x << " ";
    }
    cout << endl;
    
    for(auto x : revenue) {
        cout << x << " ";
    }
    cout << endl;*/
    
    cout << *max_element(revenue.begin(), revenue.end()) << endl;
	        
	return 0;
}

