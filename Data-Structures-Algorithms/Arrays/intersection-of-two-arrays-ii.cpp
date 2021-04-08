/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> intersectArr;
        
        int p1 = 0, p2 = 0;
        
        while (p1 < nums1.size() && p2 < nums2.size()) {
            
            if(nums1[p1] == nums2[p2]) {
                intersectArr.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            
            else if(nums1[p1] < nums2[p2]) 
                p1++;
            
            else
                p2++;
                
        }
        
        return intersectArr;
    }

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
        for(auto x: arr)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    /*
    3
    4 9 5
    5
    9 4 9 8 4
    */

    /*
    4 9
    */
    
    Solution *soln = new Solution;
    
    vector<int> arr1 = soln -> inputArr();
    vector<int> arr2 = soln -> inputArr();

    vector<int> intersectArr = soln -> intersect(arr1, arr2);

    soln -> displayArr(intersectArr);

    return 0;
}