/*
https://leetcode.com/problems/top-k-frequent-elements/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> freq; // <num, freq>  unsorted
        
        for (int i = 0; i < nums.size(); i++) {
            
            if (freq.find(nums[i]) == freq.end())
                freq[nums[i]] = 1;
            
            else
                freq[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        
        for (auto kvp : freq) 
            pq.push({kvp.second, kvp.first}); // <freq, num> sorted
        
        vector<int> top_ele;
        
        while (k--) {
            top_ele.push_back(pq.top().second); 
            pq.pop();
        }
        
        return top_ele;
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
    10 2
    1 1 1 2 2 3 3 3 3 4 
    */

    /*
    1 3
    */
    int n, k;

    Solution *soln = new Solution();
    cin >> n >> k;
    vector<int> nums = soln -> inputVector(n);
    vector<int> top_k_nums = soln -> topKFrequent(nums, k);
    soln -> displayVector(top_k_nums);

    return 0;
}