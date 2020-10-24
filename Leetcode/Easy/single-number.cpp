/*
https://leetcode.com/problems/single-number/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNumber_map(vector<int>& nums) {
        
        unordered_map<int, int> freq;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if ( freq.find(nums[i]) == freq.end() )
                freq[nums[i]] = 1;
            else
                freq[nums[i]] ++;
        }
        
        for (auto i: freq) {
            
            if(i.second == 1)
                return i.first;
        }
        
        return -1;        
    }

    int singleNumber_set(vector<int>& nums) {
        
        unordered_set <int> s;
        
        for (int i = 0; i < nums.size(); i++) {
            
            if( s.find(nums[i]) != s.end() )
                s.erase(nums[i]);
            
            else
                s.insert(nums[i]);
                
        }
        
        return *s.begin();
    }

    // Bit Manipulation
    // a ^ 0 = a
    // a ^ a = 0
    // a ^ a ^ b = (a ^ a) ^ b = 0 ^ b = b
    int singleNumber_xor(vector<int>& nums) {
        
        int a = 0;
        
        for(int i = 0; i < nums.size(); i++)
            
            a ^= nums[i];
        
        return a;
    }

    void solve_map() {
        int n, num;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        cout << singleNumber_map(nums) << endl;
    }

    void solve_set() {
        int n, num;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        cout << singleNumber_set(nums) << endl;
    }

    void solve_xor() {
        int n, num;
        cin >> n;
        vector<int> nums;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        cout << singleNumber_xor(nums) << endl;
    }
};


int main() {

    /*
    1
    6
    3
    2 1 2
    5
    4 1 2 2 1
    */

    /*
    6
    1
    4
    */

    Solution soln_map, soln_set, soln_xor;
    soln_map.solve_map();
    soln_set.solve_set();
    soln_xor.solve_xor();

    return 0;
}

