/*
https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int computeSum(vector<int>&  nums, int x) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum+= ceil((float)nums[i]/(float)x );
        }
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        // bin search
        int left = 1;
        int right = nums[nums.size() - 1];
        
        while (left <= right) {
            
            int pivot = left + (right - left )/2;
            
            int divisor = computeSum(nums, pivot);
            
            if (divisor > threshold) 
                left = pivot + 1;
            else
                right = pivot - 1;
        }
        
        // at the end of loop, left > right,
        // computeSum(right) > threshold
        // computeSum(left) <= threshold
        // --> return left
        return left;
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
};

int main() {
    
    /*
    4
    1 2 5 9
    6
    */

    /*
    5
    */

    /*
    We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
    If the divisor is 4 we can get a sum to 7 (1+1+2+3) and 
    if the divisor is 5 the sum will be 5 (1+1+1+2). 
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    int n;
    cin >> n;

    cout << soln -> smallestDivisor(arr, n) << endl;

    return 0;
}