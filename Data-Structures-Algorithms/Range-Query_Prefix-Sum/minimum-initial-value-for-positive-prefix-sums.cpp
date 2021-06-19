/*
https://binarysearch.com/problems/Minimum-Initial-Value-for-Positive-Prefix-Sums
*/

#include <bits/stdc++.h>
using namespace std;

int minstartnum(vector<int>& nums) {
    
    if(nums.size() == 0)
        return 1;

    int min_sum = nums[0];
    int prefix_sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        prefix_sum += nums[i];
        min_sum = min(prefix_sum, min_sum);
    }
    
    if (min_sum > 0)
        return 1;
    
    return 1 - min_sum;
}

/*
Input
4
2 -5 3 2

Output
4

Explanation
If we have append 4 to the list then we have [4, 2, -5, 3, 2].
The prefix sums are then [4, 6, 1, 4, 6], all of which are > 0.
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << minstartnum(v) << endl;
    return 0;
}