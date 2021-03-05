/*
https://leetcode.com/problems/check-array-formation-through-concatenation/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSubArray(vector<int>& arr, vector<int>& pi, int ai, int pi_size) {
        
        for(int ii = 0; ii < pi_size; ii++) {
            
            //cout << arr[ai] << " " << pi[ii] << endl;
            
            if (arr[ai] != pi[ii])    
                return false;
            
            else 
                ai++;
        }
        
        return true;
    }
    
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        
        vector<int> pos(102, -1);
        
        for (int i = 0; i < arr.size(); i++) 
            pos[arr[i]] = i;
        
        
        for (int pi = 0; pi < pieces.size(); pi++) {
            
            int ai = pos[pieces[pi][0]];
            //cout << ai << endl;
            
            if (ai != - 1) {
                if (! isSubArray(arr, pieces[pi], ai, pieces[pi].size()) )
                    return false;
            }
            else
                return false;
        }
        
        return true;
    }

    vector<int> inputArr() {
        vector<int> arr;
        int n, num; 
        cin >> n;
        while(n-- > 0) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }

    vector<vector<int>> inputPieces() {
        vector<vector<int>> pieces;
        int n;
        cin >> n;
        while(n-- > 0) 
            pieces.push_back(inputArr());
        return pieces;
    }
};

int main() {
    
    /*
    7
    100 2 98 28 44 55 37
    2
    3
    28 46 57
    4
    37 19 40 38
    *
    /

    /*
    0
    */
    
    /*
    4
    91 4 64 78
    3
    1
    78
    2
    4 64
    1
    91
    */

    /*
    1
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();
    vector<vector<int>> pieces = soln -> inputPieces();
    cout << soln -> canFormArray(arr, pieces) << endl;

    return 0;
}