/*
https://binarysearch.com/problems/Three-Player-Coin-Game
*/

#include <bits/stdc++.h>
using namespace std;

/*
You are given a list of non-negative integers piles where 
each piles[i] represents the number of coins on pile i. 

In each move, you can do the following until there's no more coins:
    Pick any 3 piles from piles
    A friend will take the pile with the maximum number of coins
    You will take the next highest pile
    A friend will take the last pile

Return the maximum number of coins you can acquire.
*/

int maxcoins(vector<int>& piles) {
    
    sort(piles.begin(), piles.end());

    int count = 0;

    int i = piles.size() - 2;

    int sum = 0;

    while (count < piles.size() / 3) {
        
        sum += piles[i];
        count++;
        i -= 2;
    }

    return sum;
}

/*
Input
6
2 4 1 3 5 6

Output
8

Explanation
First, we can pick the coins [6, 5, 1], yielding us 5 coins. 
Then we can pick 4, 3, 2 which yields us 3 coins.
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) 
        cin >> v[i];
    cout << maxcoins(v) << endl;
    return 0;
}