/*
https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3270/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    //  4  3  2  7  8  2  3  1
    //  4  3  2 -7  8  2  3  1
    //  4  3 -2 -7  8  2  3  1
    //  4 -3 -2 -7  8  2  3  1
    //  4 -3 -2 -7  8  2 -3  1
    //  4 -3 -2 -7  8  2 -3 -1
    // -4 -3 -2 -7  8  2 -3 -1
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {       
        
        vector<int> nonums;
        int index_to_be_marked;
        
        for(int i = 0; i < nums.size(); i++) {
            index_to_be_marked = abs(nums[i]) - 1;
            nums[index_to_be_marked] = abs(nums[index_to_be_marked]) * -1;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                nonums.push_back(i + 1);
        }
        
        return nonums;
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

    void displayArr(vector<int> nums) {
        for( auto x : nums )
            cout << x << " ";
        cout << endl;
    }
};

int main() {

    /*
    8
    4 3 2 7 8 2 3 1
    */

    /*
    5 6
    */

    Solution *soln = new Solution;

    vector<int> nums_arr = soln -> inputArr();
    
    vector<int> disappeared_nums_arr = soln -> findDisappearedNumbers(nums_arr);

    soln -> displayArr(disappeared_nums_arr);

    return 0;
}