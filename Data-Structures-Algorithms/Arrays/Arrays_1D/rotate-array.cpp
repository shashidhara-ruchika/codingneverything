/*
https://leetcode.com/problems/minimum-height-trees/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k = k % nums.size();
        
        int count = 0;
        
        for (int start = 0; count < nums.size(); start++) {
            
            int curr = start, prev = nums[start];
            
            while (true) {
                
                int next = (curr + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                count++;
                
                if (start == curr)
                    break;
            }
            
        
        }
        return;
    }

    void rotate_rev(vector<int>& nums, int k) {
        
        k %= nums.size();
        
        reverse(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.begin() + k);
        
        reverse(nums.begin() + k, nums.end());
        
        return;
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr;
        while(n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }

    void displayArr(vector<int> arr) {
        for(auto x: arr) 
            cout << x << " ";
        cout << endl;
        return;
    }
};

int main() {

    /*
    7
    1 2 3 4 5 6 7
    3
    4
    -1 -100 3 99
    2
    */

    /*
    5 6 7 1 2 3 4
    3 99 -1 -100
    */

    Solution *soln1 = new Solution;
    vector<int> arr1 = soln1 -> inputArr();
    int k1; 
    cin >> k1;
    soln1 -> rotate(arr1, k1);
    soln1 -> displayArr(arr1);

    Solution *soln2 = new Solution;
    vector<int> arr2 = soln2 -> inputArr();
    int k2; 
    cin >> k2;
    soln1 -> rotate(arr2, k2);
    soln1 -> displayArr(arr2);

    return 0;
}