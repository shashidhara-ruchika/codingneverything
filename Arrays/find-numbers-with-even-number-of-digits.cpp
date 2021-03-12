/*
https://leetcode.com/explore/learn/card/fun-with-arrays/521/introduction/3237/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int findNumbers_log(vector<int>& nums) {
        
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if ((int)(floor(log10((double)nums[i]))+ 1) % 2 == 0) {
                count++;                
            }
        }
        
        return count;
    }

    int findNumbers(vector<int>& nums) {
        
        int count_num = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            
            int num = nums[i];
            int count_digits = 0;
            
            while(num > 0) {
                num /= 10;
                count_digits++;
            }
            
            if (count_digits % 2 == 0)
                count_num++;
        }
        
        return count_num;
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
    6
    1 46 1 8 1 1 1
    5
    78 66 55 42 12
    */

    /*
    2
    4
    */
   
    Solution *soln = new Solution;
    Solution *soln_log = new Solution;

    vector<int> arr1 = soln -> inputArr();
    cout << soln_log -> findNumbers(arr1) << endl;

    vector<int> arr2 = soln -> inputArr();
    cout << soln -> findNumbers_log(arr2) << endl;    

    return 0;
}