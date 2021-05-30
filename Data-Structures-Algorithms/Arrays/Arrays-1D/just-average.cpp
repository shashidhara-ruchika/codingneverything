/*
https://binarysearch.com/problems/Just-Average
*/

#include <bits/stdc++.h>
using namespace std;

bool possible_to_remove(vector<int>& nums, int k) {
    int actual_sum = k * (nums.size() - 1);
    int curr_nums_sum = accumulate(nums.begin(), nums.end(), 0);
    int num_to_be_removed = curr_nums_sum - actual_sum;
    if (find(nums.begin(), nums.end(), num_to_be_removed) != nums.end())
        return true;
    else 
        return false;
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
4
1 2 3 10
3

Output
1
*/

int main() {
    vector<int> nums = input_vector();
    int k;
    cin >> k;
    cout << possible_to_remove(nums, k) << endl;
    return 0;
}