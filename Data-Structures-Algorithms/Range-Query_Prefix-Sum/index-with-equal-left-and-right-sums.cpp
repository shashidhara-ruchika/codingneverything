/*
https://binarysearch.com/problems/Index-with-Equal-Left-and-Right-Sums
*/

#include <bits/stdc++.h>
using namespace std;

int get_index(vector<int>& nums) {

    if (nums.size() < 2)    
        return 0;
    
    vector<long long> left(nums.size(), 0);
    left[0] = (long long)nums[0];

    vector<long long> right(nums.size(), 0);
    right[nums.size() - 1] = (long long)nums[nums.size() - 1];

    for (int i = nums.size() - 2; i >= 0; i--)
        right[i] = (long long)nums[i] + (long long)right[i + 1];

    if(left[0] == right[0])
        return 0;

    for (int i = 1; i < nums.size(); i++) {
        left[i] = (long long)nums[i] + (long long)left[i - 1];  
        if (left[i] == right[i])
            return i;
    }
    
    return -1;

}

/*
Input
7
2 3 4 0 5 2 2

Output
3

Explanation
Sum of the numbers left of index 3 is 9 and sum of the numbers right of index 3 also 9.
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << get_index(v) << endl;
    return 0;
}
