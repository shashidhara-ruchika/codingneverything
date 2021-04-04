/*
https://leetcode.com/problems/sort-array-by-parity/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int curr_index = 0, last_even_index = 0;

        while (curr_index < nums.size()) {
            
            if(nums[curr_index] % 2 == 0) {
                swap(nums[last_even_index], nums[curr_index]);
                last_even_index++;
            }
            curr_index++;
        }
        return nums;
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

    void displayArr(vector<int> v) {
        for(auto x: v)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    
    /*
    4
    3 1 2 4
    */

    /*
    2 4 1 3
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();

    vector<int> new_arr =  soln -> sortArrayByParity(arr);

    soln -> displayArr(new_arr);

    return 0;
}