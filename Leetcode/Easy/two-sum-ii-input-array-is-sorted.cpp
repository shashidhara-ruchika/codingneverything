/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum_twopointer(vector<int>& numbers, int target) {
        
        int l = 0, r = numbers.size() - 1, sum;
        vector<int> index_pair;
        
        while ( l < r ) {
            
            sum = numbers[l] + numbers[r];
            
            if (sum == target) {
                index_pair.push_back(l + 1);
                index_pair.push_back(r + 1);
                return index_pair;
            }
            else {
                if (sum > target)
                    r--;
                else
                    l++;                
            }
                
        }
        return index_pair;        
    }

     vector<int> twoSum_unorderedmap(vector<int>& numbers, int target) {
        
        unordered_map<int, int> sum_pairs;
        
        for(int i = 0; i < numbers.size(); i++) {
            
            if (sum_pairs.find(target - numbers[i]) != sum_pairs.end()) {
                
                if (i < sum_pairs[target - numbers[i]])
                    return {i + 1, sum_pairs[target - numbers[i]] + 1};              
                else
                    return {sum_pairs[target - numbers[i]] + 1, i + 1};              
            }                
            else
                sum_pairs[numbers[i]] = i;  
            
        }
        return {0, 0};       
    }

    vector<int> inputArr() {

        int n, target, num;
        vector<int> nums;       
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        return nums;
    }
};

int main() {

    /*
    4
    2 7 11 15
    9
    */
    
    /*
    1 2
    */

    Solution *soln_twopointer = new Solution;
    vector<int> nums1 = soln_twopointer -> inputArr();
    int target1;    
    cin >> target1;

    vector<int> sum_pair1 = soln_twopointer -> twoSum_twopointer(nums1, target1);

    cout << sum_pair1[0] << " " << sum_pair1[1] << endl;       
    

    /*
    3
    -1 0 11
    -1
    */
    
    /*
    1 2
    */
   
   Solution *soln_unorderedmap = new Solution;
    vector<int> nums2 = soln_unorderedmap -> inputArr();
    int target2;    
    cin >> target2;

    vector<int> sum_pair2 = soln_unorderedmap -> twoSum_twopointer(nums2, target2);

    cout << sum_pair2[0] << " " << sum_pair2[1] << endl;   
   


}
