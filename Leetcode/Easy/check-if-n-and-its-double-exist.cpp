/*
https://leetcode.com/explore/learn/card/fun-with-arrays/527/searching-for-items-in-an-array/3250/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    // checking if arr[i] * 2 = arr[j] where i != j
    bool checkIfExist(vector<int>& arr) {
        
        unordered_set<int> s;
        
        int count0 = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            
            if (arr[i] == 0) {
                count0++;
                if (count0 > 1)
                    return true;
            }
            
            else if ( s.find(arr[i]*2) != s.end() || (arr[i] % 2 == 0 && s.find(arr[i]/2) != s.end()) ) 
               return true; 
            
            else
                s.insert(arr[i]);                
        }
        
        if (count0 > 1)
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
    4
    7 11 14 0
    */

    /*
    1
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();

    cout << soln -> checkIfExist(arr) << endl;

    return 0;
}