/*
https://binarysearch.com/problems/Buying-Cars
*/

#include <bits/stdc++.h>

using namespace std;

int count_cars(vector<int>& prices, int k) {
    
    sort(prices.begin(), prices.end());

    int sum = 0;
    int count = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (sum + prices[i] <= k) {
            sum += prices[i];
            count++;
        }
    }
    return count;
}

/*
Example 1

Input
5
90 30 20 40 90

95
Output
3

Explanation
We can buy the cars with prices 30, 20, and 40.

Example 2

Input
4
60 90 55 75
50

Output
0

Explanation
We cannot afford any of these cars.
*/
int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    int k;
    cin >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << count_cars(v, k) << endl;
    return 0;
}


