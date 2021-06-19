/*
https://binarysearch.com/problems/K-Prefix
*/

#include <bits/stdc++.h>
using namespace std;

int kPrefix(vector<int>& nums, int k) {
    
    if (nums.size() == 0)
        return -1;
    
    if (nums.size() == 1) {
        if (nums[0] <= k)
            return 0;
        else
            return -1;
    }
        
    vector<long long> prefix_sum(nums.size(), 0);
    prefix_sum[0] = (long long)nums[0];

    for(int i = 1; i < nums.size(); i++) 
        prefix_sum[i] = (long long)nums[i] + prefix_sum[i - 1];

    for (int i = prefix_sum.size() - 1; i >= 0; i--) {
        if (prefix_sum[i] <= k)
            return i;
    }

    return -1;    
}

/*
Input
5
3 -5 4 1 6
4

Output
3

Explanation
The largest i here is 3, since we have nums[0] + ... + nums[3] = 3 
and if we added the next number (6) the sum would no longer be less than k.
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    cout << kPrefix(v, k) << endl;
    return 0;
}