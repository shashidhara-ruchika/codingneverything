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

    void solve_twopointer() {

        int n, target, num;
        vector<int> nums;       
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        cin >> target;

        vector<int> sum_pair = twoSum_twopointer(nums, target);

        cout << sum_pair[0] << " " << sum_pair[1] << endl;     
    } 

    void solve_unorderedmap() {

        int n, target, num;
        vector<int> nums;       
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> num;
            nums.push_back(num);
        }
        cin >> target;

        vector<int> sum_pair = twoSum_unorderedmap(nums, target);

        cout << sum_pair[0] << " " << sum_pair[1] << endl;              
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

    Solution soln_twopointer;
    soln_twopointer.solve_twopointer();

    /*
    3
    -1 0 11
    -1
    */
    
    /*
    1 2
    */
   
    Solution soln_unorderedmap;
    soln_unorderedmap.solve_unorderedmap();


}
