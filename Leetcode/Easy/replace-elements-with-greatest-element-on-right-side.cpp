/*
https://leetcode.com/explore/learn/card/fun-with-arrays/511/in-place-operations/3259/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    
    // [17,18,5,4,6, 1]
    // [18, 6,6,6,1,-1]
    vector<int> replaceElements(vector<int>& arr) {
        
        int i = arr.size() - 2;
        
        int prev_arr_i = arr[arr.size() - 1];
        arr[arr.size() - 1] = -1;
        
        while(i >= 0) {            
            
            int curr_arr_i = arr[i];
            arr[i] = max(arr[i + 1], prev_arr_i);
            prev_arr_i = curr_arr_i;
            
            i--;
        }
        
        return arr;
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
    6
    17 18 5 4 6 1
    */

    /*
    18 6 6 6 1 -1
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();

    vector<int> new_arr =  soln -> replaceElements(arr);

    soln -> displayArr(new_arr);

    return 0;
}



