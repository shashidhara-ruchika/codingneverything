/*
https://leetcode.com/problems/shuffle-an-array/
*/

# include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> array;
    vector<int> original;
    
    Solution(vector<int>& nums) {
        array = nums;
        for(int i = 0; i < nums.size(); i++)
            original.push_back(nums[i]);
    }
    
    /** Resets the array to its original configuration and return it. **/
    vector<int> reset() {
        return original;
    }
    
    void swapAt(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
    
    /** Returns a random shuffling of the array. **/
    vector<int> shuffle() {
        for (int i = 0; i < array.size(); i++)
            swapAt(i, rand() % array.size());
        return array;
        
    }
};

class ArrayHelper {
public:
    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> num;
            arr[i] = num;
        }
        return arr;
    }

    void displayArr(vector<int> arr) {
        for (auto x : arr)
            cout << x << " ";
        cout << endl;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


int main () {

    /*
    5
    1 2 3 4 5
    5
    reset
    shuffle
    shuffle
    reset
    shuffle
    */

    /*
    1 2 3 4 5
    4 3 5 2 1
    1 2 5 3 4
    1 2 3 4 5
    2 4 3 1 5
    */

    ArrayHelper *arrhelper = new ArrayHelper;
    vector<int> arr = arrhelper -> inputArr();

    Solution *obj = new Solution(arr);

    int num_op;
    cin >> num_op;

    string s;
    while (num_op-- > 0) {
        
        cin >> s;

        if (s == "shuffle") {
            vector<int> shuffled_arr = obj -> shuffle();
            arrhelper -> displayArr(shuffled_arr);
        }

        else if (s == "reset") {
            vector<int> reset_arr = obj -> reset();
            arrhelper -> displayArr(reset_arr);
        }

        else
            continue;
    }

    return 0;
}
