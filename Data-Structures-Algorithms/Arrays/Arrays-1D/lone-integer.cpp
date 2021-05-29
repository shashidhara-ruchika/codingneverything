/*
https://binarysearch.com/problems/Lone-Integer
*/

# include <bits/stdc++.h>
using namespace std;

int solve1(vector<int> nums) {
    map<int, int> freq;
    int lone_num = -1;
    for(int i = 0 ; i < nums.size(); i++) {
        if (freq.find(nums[i]) == freq.end())
            freq[nums[i]] = 1;
        else
            freq[nums[i]]++;
    }
    for(auto key : freq) {
        if(key.second == 1)
            lone_num = key.first;
    }
    return lone_num;
}

int solve2(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int lone_num = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[i + 1])
            lone_num = -1;
        else 
            lone_num = nums[i];
    }
    return lone_num;
}

int solve3(vector<int> nums) {
    int num = 0;
    int n = 0;
    while (n < 32) {
        // count set bits at position nth
        int cnt_set_bits = 0;
        for (auto x : nums) {
            if ((x >> n) & 1) cnt_set_bits++;
        }
        if (cnt_set_bits % 3 != 0) {
            num += (1 << n);
        }
        n++;
    }
    return num;
}

/*
Input
7
2 2 2 9 5 5 5
Output
9
*/