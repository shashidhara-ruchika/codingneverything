/*
https://leetcode.com/problems/intersection-of-two-arrays/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, pair<bool, bool>> nums_map;
        vector<int> nums_intersect;
        
        for (auto num: nums1) {
            if (nums_map.find(num) == nums_map.end())
                nums_map[num] = {true, false};
        }            
        
        for (auto num: nums2) {
            if (nums_map.find(num) == nums_map.end())
                nums_map[num] = {false, true};
            else
                nums_map[num].second = true;
        }
            
        
        for (auto num: nums_map) {
            if (num.second.first == true && num.second.second == true)
                nums_intersect.push_back(num.first);
        }
            
        return nums_intersect;
    }

    vector<int> intersection_status(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nums_map;
        vector<int> nums_intersect;
        
        for (auto num: nums1) {
            if (nums_map.find(num) == nums_map.end())
                nums_map[num] = 1;
        }            
        
        for (auto num: nums2) {
            if (nums_map.find(num) == nums_map.end())
                nums_map[num] = 2;
            else if (nums_map[num] == 1)
                nums_map[num] = 3;
            
        }
            
        
        for (auto num: nums_map) {
            //cout << num.first << " " << num.second << endl;
            if (num.second == 3)
                nums_intersect.push_back(num.first);
        }
            
        return nums_intersect;
    }

    vector<int> inputVector(int n) {
        int num;
        vector<int> nums;
        while(n--) {
            cin >> num;
            nums.push_back(num);
        }
        return nums;
    }

    void displayVector(vector<int> nums) {
        for (auto num : nums) 
            cout << num << " ";
        cout << endl;
    }
};


int main() {
    /*
    4
    4 5 5 2
    7 
    1 2 3 4 3 2 1
    */

    // output intersected array need not be in the same order
    /*
    2 4
    4 2
    */

    int n1, n2;
    Solution *soln = new Solution();

    cin >> n1;
    vector<int> a1 = soln -> inputVector(n1);

    cin >> n2;
    vector<int> a2 = soln -> inputVector(n2);

    vector<int> intersect1 = soln -> intersection(a1, a2);
    soln -> displayVector(intersect1);

    vector<int> intersect2 = soln -> intersection_status(a1, a2);
    soln -> displayVector(intersect2);

    return 0;
}