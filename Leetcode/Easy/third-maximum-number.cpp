/*
https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3231/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int thirdMax_set(vector<int>& nums) {       
            
        set<int> s(nums.begin(), nums.end());

        auto max_it = max_element(s.begin(), s.end());
        
        if(s.size() > 2) {           
            for(int i = 1; i <= 2; i++) {
                s.erase(max_it);            
                max_it = max_element(s.begin(), s.end());
            }      
        }
        return *max_it;      
    }

    int thirdMax(vector<int>& nums) {
        int max1 = INT_MIN,max2 = INT_MIN,max3 = INT_MIN;

        bool min = false;

        for(int i=0;i<nums.size();i++){

            if(nums[i] == INT_MIN)
                min = true;

            if(nums[i]==max1 || nums[i]==max2 || nums[i]<=max3)
                continue;

            if(nums[i]>max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            
            else if(nums[i]>max2){
                max3 = max2;
                max2 = nums[i];
            }
            
            else{
                max3 = nums[i];
            }
        }

        if(max2 == INT_MIN || max3 == INT_MIN && !min)
            return max1;
            
        return max3;
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
    2 2 1 3
    3
    2 1 1
    */

    /*
    1
    2
    */

    Solution *soln_set = new Solution;
    vector<int> v1 = soln_set -> inputArr();
    cout << soln_set -> thirdMax_set(v1);

    Solution *soln = new Solution;
    vector<int> v2 = soln -> inputArr();
    cout << soln -> thirdMax(v2);

    return 0;
}