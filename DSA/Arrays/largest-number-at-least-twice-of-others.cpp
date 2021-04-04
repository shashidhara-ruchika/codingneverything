/*
https://leetcode.com/problems/largest-number-at-least-twice-of-others/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // keep track of 1st max & 2nd max in one traversal itself
    // then check if 2nd max * 2 < 1st max, return 1st max index, else return -1
    int dominantIndex(vector<int>& nums) {
        
        int max1 = -1, max2 = -1, max1_in, max2_in;
        
        for(int i = 0; i < nums.size(); i++) {
            
            
            if (nums[i] > max1) {
                
                max2_in = max1_in;
                max2 = max1;
                
                max1_in = i;
                max1 = nums[i];
            }
            
            else if (nums[i] > max2) {
                
                max2_in = i;
                max2 = nums[i];       
            }
        }
        
        if (max2 * 2 <= max1)
            return max1_in;
        else
            return -1;
    }

    // find 1st max in the first traversal
    // then perform second traversal and
    // return -1 if any num * 2 > 1st max, else return 1st index
    int dominantIndex2(vector<int>& nums) {
        
        auto max_in = max_element(nums.begin(), nums.end());
        
        for (auto in = nums.begin(); in < nums.end(); in++) {
            
            if (in != max_in && *in * 2 > *max_in) 
                return -1;               
        }
        return max_in - nums.begin();
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> nums;
        while(n--) {
            cin >> num;
            nums.push_back(num);
        }
        return nums;
    }
};

int main() {

    /*
    4
    3 6 1 0
    4
    1 2 3 4
    */

    /*
    1
    -1
    */

    Solution *soln1 = new Solution;
    vector<int> nums1 = soln1 -> inputArr();
    cout << soln1 -> dominantIndex(nums1) << endl;

    Solution *soln2 = new Solution;
    vector<int> nums2 = soln2 -> inputArr();
    cout << soln2 -> dominantIndex(nums2) << endl;

    return 0;
}