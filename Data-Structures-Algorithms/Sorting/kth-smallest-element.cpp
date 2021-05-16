/*
https://binarysearch.com/problems/Kth-Smallest-Element
*/

# include <bits/stdc++.h>

using namespace std;

int solve1(vector<int>& nums, int k) {

    make_heap(nums.begin(), nums.end());
    sort_heap(nums.begin(), nums.end());

    return nums[k];
}

int solve2(vector<int>& nums, int k) {
    
    sort(nums.begin(), nums.end());

    return nums[k];
}

// works only for positive integers
int solve3(vector<int>& nums, int k) {

    auto max_it = max_element(nums.begin(), nums.end());
    int index = distance(nums.begin(), max_it);
    vector<int> v(index + 1, 0);
    for(auto val : nums) {
        v[val]++;
    }
    int i = 0;
    int ki = 0;
    int k_num = -1;
    while(i < index + 1) {
        ki += v[i];
        if(ki >= k) {
            k_num = i;
        }
        i++;
    }
    return k_num;
}

/*
Input
5
5 3 8 2 0
2

Output
3

Explanation
When sorted the numbers are [0, 2, 3, 5, 8] and index 2's value is 3.
*/

int main()
{
    int n, num, k;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    while(n-- > 0) {
        cin >> num;
        v1.push_back(num);
        v2.push_back(num);
        v3.push_back(num);
    }
    cin >> k;

    cout << solve1(v1, k) << endl;
    cout << solve2(v2, k) << endl;
    cout << solve3(v3, k) << endl;

    return 0;
}