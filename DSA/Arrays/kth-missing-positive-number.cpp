/*
https://leetcode.com/problems/kth-missing-positive-number/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int findKthPositive(vector<int>& arr, int k) {
        
        // if k < first num in the arr, return k itself
        if (k < arr[0])
            return k;
        
        // count keeps track of count of missing numbers
        // i is used to track all numbers from 0 to 1000
        // arri is used to track index of array
        int count = arr[0] - 1;
        int i = arr[0];
        int arri = 0;
        
        // until count < k and arri doesn't exceed size of arr
        while (count < k && arri < arr.size()) {
            
            // if i doesn't match element in the arr, i is missing, increment count
            if (i != arr[arri])
                count++;
            // else i matches element in the arr, i is present, increment arri
            else
                arri++;
            
            // if count reaches k, return i
            if (count == k)
                return i;
            
            // increment i every iteration
            i++;            
        }
        
        // if count < k, add the remaining count of the missing numbers i.e. (k - (count + 1)) with i & return 
        return i + k - count - 1;
    }

    /*
                1 2 3 4 5
    inp array = 2 3 4 7 11, k = 2

    The gist of the solution here is to localize where in the array there are missing K amount of numbers, 
    because the array is already sorted we can use a variation of Binary Search. 
    Because the array is sorted and if there were no missing numbers we would know that each index represents 
    the maximum amount of numbers up to this index, for example:

                  1 2 3     4         5
    inp array = 1 2 3 4 5 6 7 8 9 10 11
                ^       ^ ^   ^ ^ ^
    
    7  - 4 = 3, count of missing nums = 3
    This example shows there are 3 missing numbers before the number 7 which are [1, 5, 6]

    11 - 5 = 6, count of missing nums = 6 
    This example shows there are 6 missing numbers before the number 11 which are [1, 5, 6, 8, 9, 10]

    We can start applying this logic to a recursive Binary Search:

    * End condition: if left index > right index
        * Get middle Index
        * If there are more than or euqal K numbers to the left of middle
                * Go recursivley to left side of array
        * Else if, There are less than K numbers to the left of middle
                * Go recursivley to right side of array
                
    * Once we reach the end condition we are at an index where we know that 
        either to the left (inclusive) there are more or equal missing numbers to K, 
        or the right (exclusive) where k is bigger than missing numbers.
        
    */

    int findKthPositive_binSearch(vector<int>& arr, int k) {
        
        if(k < arr[0])
            return k;
        
        int low = 0, high = arr.size();
        
        while(low < high) {

            int mid = low + ((high - low) >> 1);

            if(arr[mid] - mid - 1 < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low + k;
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr;
        while (n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }
};

int main() {
    /*
    5
    2 3 4 7 11
    5
    */

    /*
    4
    1 2 3 4
    2
    */

    /*
    9
    */

    /*
    6
    */

    Solution *soln = new Solution;
    int k; 
    vector<int> arr = soln -> inputArr();
    cin >> k;
    cout << soln -> findKthPositive(arr, k) << endl;

    Solution *soln_bs = new Solution;
    int k_bs; 
    vector<int> arr_bs = soln_bs -> inputArr();
    cin >> k_bs;
    cout << soln_bs -> findKthPositive_binSearch(arr_bs, k_bs) << endl;

    return 0;   
}