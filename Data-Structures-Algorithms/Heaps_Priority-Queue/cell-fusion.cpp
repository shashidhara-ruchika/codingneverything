/*
https://binarysearch.com/problems/Cell-Fusion
*/

#include <bits/stdc++.h>

using namespace std;

int fusedCell(vector<int>& cells) {
    priority_queue<int> pq(cells.begin(), cells.end());
    while(pq.size() > 1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        if(n1 != n2) 
            pq.push( floor((n1 + n2) / 3) );
    }
    if(pq.size() == 0)
        return -1;
    else
        return pq.top();
}

/*
Input
4
10 30 30 20

Output
10

Explanation
In the first iteration, the two largest cells 
both have the size of 30 so they both die. 
In the second iteration, cells 10, and 20 merge to become 10.
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) 
        cin >> v[i];    
    cout << fusedCell(v) << endl;
    return 0;
}