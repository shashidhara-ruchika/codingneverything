/*
https://binarysearch.com/problems/Sorted-Elements
*/

#include <bits/stdc++.h>
using namespace std;

// find ele if sorted, are in the same position
int solve(vector<int>& nums) {
    vector<int> sorted_nums;
    sorted_nums.assign(nums.begin(), nums.end());
    sort(sorted_nums.begin(), sorted_nums.end());
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == sorted_nums[i])
            count++;
    }
    return count;
}

/*
Input
5
1 7 3 4 10

Output
2

Explanation
Comparing nums and its sorted version we find that 
elements 1 and 10 are in their correct positions.
[1, 7, 3, 4, 10]
[1, 3, 4, 7, 10]
*/

int main() {
    int n, num;
    vector<int> arr;
    while(n-- > 0) {
        cin >> num;
        arr.push_back(num);
    }
    cout << solve(arr) << endl;
    return 0;
}