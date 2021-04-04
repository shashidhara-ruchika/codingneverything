/*
https://leetcode.com/problems/valid-mountain-array/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        
        if (A.size() == 0)
            return false;
        
        int i = 0;
        
        while (i < A.size() - 1 && A[i] < A[i + 1]) 
            i++;
        
        if(i == 0 || i == A.size() - 1)
            return false;
        
        while(i < A.size() - 1 && A[i] > A[i + 1])
            i++;
        
        if (i == A.size() - 1)
            return true;
        
        else
            return false;        
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
    8
    0 2 3 3 5 2 1 0
    */

    /*
    0
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();

    cout << soln -> validMountainArray(arr) << endl;

    return 0;
}
