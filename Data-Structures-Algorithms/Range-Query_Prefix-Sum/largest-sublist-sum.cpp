/*
https://binarysearch.com/problems/Largest-Sublist-Sum
*/

#include <bits/stdc++.h>
using namespace std;

int larget_sublist_sum(vector<int>& nums) {
    
    int curr_sum = INT_MIN;
    int global_sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        
        global_sum = global_sum + nums[i];

        if (curr_sum < global_sum)
            curr_sum = global_sum;
        
        if (global_sum < 0)
            global_sum = 0;
    }
    return curr_sum;
}

/*
Input
6
10 -5 12 -100 3 -1 20

Output
22

Explanation
[3, -1, 20] is the contiguous sublist with the largest sum.


Input
4
3 4 -2 5

Output
10

Explanation
We can take the whole list and its sum is 3 + 4 - 2 + 5 = 10
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << larget_sublist_sum(v);
    return 0;
}