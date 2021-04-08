/*
https://leetcode.com/problems/duplicate-zeroes/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int count0 = 0, last_copy = 0;
        
        // find the count of zeroes and last copy index
        while (last_copy < arr.size()) {
            
            if(arr[last_copy] == 0) 
                count0++;
            count0++;
            
            // break when count of zeroes exceeeds size of arr
            if(count0 >= arr.size())
                break;
            
            last_copy++;            
        }
        
        int curr = arr.size() - 1;
        
        // for the edge case when duplication of zero overflows size of arr, 
        // here we just copy without duplication
        if(count0 > arr.size())
            arr[curr--] = arr[last_copy--];
        
        
        // traverse from end of arr and keep duplicating from last copy index
        // decrement end of arr & last copy arr indexes
        while (last_copy >= 0 && curr >= 0) {
            
            if(arr[last_copy] == 0) {
                arr[curr--] = 0;
                arr[curr--] = 0;
                last_copy--;
            }
            else {
                arr[curr--] = arr[last_copy--];
            }
                
        }
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

    void displayArr(vector<int> &arr) {
        for(auto x: arr)
            cout << x << " ";
        cout << endl;
    }
};

int main() {

    /*
    8
    1 0 2 3 0 4 5 0
    */
    
    /*
    1 0 0 2 3 0 0 4
    */
    
    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    soln -> duplicateZeros(arr);
    soln -> displayArr(arr);
    
    return 0;
}