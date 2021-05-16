/*
https://www.geeksforgeeks.org/maximum-adjacent-difference-array-sorted-form/
https://binarysearch.com/problems/Largest-Gap
*/

# include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int max_diff = nums[1] - nums[0];
    for (int i = 1; i < nums.size(); i++) {
        //cout << nums[i] - nums[i - 1] << endl;
        max_diff = max(max_diff, nums[i] - nums[i - 1]);
    }
    return max_diff;
}

/*
Input
nums = [4, 1, 2, 8, 9, 10]

Output
4

Explanation
The largest gap is between 4 and 8.
*/

int main()
{
    vector<int> arr;
    int n, num;
    cin >> n;
    while(n -- > 0)
    {
        cin >> num;
        arr.push_back(num);
    }
    cout << solve(arr) << endl;
    return 0;
}