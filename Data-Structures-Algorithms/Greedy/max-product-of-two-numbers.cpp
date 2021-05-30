/*
https://binarysearch.com/problems/Max-Product-of-Two-Numbers
*/

#include <bits/stdc++.h>
using namespace std;

int solve0(vector<int>& nums) {    
    int max_val = max(nums[0], nums[1]);
    int min_val = min(nums[0], nums[1]);
    int max_prod = nums[0] * nums[1];
    for (int i = 2; i < nums.size(); i++) {
        max_prod = max(max_prod, max(nums[i] * max_val, nums[i] * min_val));
        max_val = max(max_val, nums[i]);
        min_val = min(min_val, nums[i]);
    }
    return max_prod;
}

int solve1(vector<int>& nums) {

    if (nums.size() == 2) 
        return nums[0] * nums[1];

    priority_queue<int> pos;
    priority_queue<int> neg;
    int count0 = 0;

    for(auto n : nums) {
        if (n == 0)
            count0++;
        else if (n > 0) 
            pos.push(n);
        else 
            neg.push(n * -1);
    }

    if (count0 > nums.size() - 2) 
        return 0;

    int pos_prod = INT_MIN, neg_prod = INT_MIN;

    if(pos.size() > 1)  {
        pos_prod = pos.top();
        pos.pop();
        pos_prod *= pos.top();
    }
    if (neg.size() > 1) {
        neg_prod = neg.top();
        neg.pop();
        neg_prod *= neg.top();
    }

    if (pos_prod != INT_MIN && pos_prod >= neg_prod)
        return pos_prod;
    
    if (neg_prod != INT_MIN && neg_prod >= pos_prod)
        return neg_prod;
    
    return 0;
}

vector<int>& input_vector() {
    int n, num;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
    }
    return nums;
}

/*
Input
5
-7 2 5 -2 0

Output
14
14
*/

int main() {
    
    vector<int> nums = input_vector();
    cout << solve0(nums) << endl;
    cout << solve1(nums) << endl;
    return 0;
}