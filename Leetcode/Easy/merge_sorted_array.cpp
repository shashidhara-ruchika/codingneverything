/*
https://leetcode.com/problems/merge-sorted-array/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // copy to first m elements of nums1 to the last m elements of num1
        // [1, 4, 7, 8, 0, 0] => [0, 0, 1, 4, 7, 8]
        
        int p1 = m + n - 1;
        int p2 = m - 1; 
        int pi;
        
        
        while (p2 >= 0) {
            nums1[p1] = nums1[p2];
            p1--;
            p2--;
        }
        
        // perform merge sort from nums1[n : m + n] and nums2[0 : n] into nums1[0 : m + n]
        
        p1 = n;
        p2 = 0;
        pi = 0;
        
        while (p1 < m + n && p2 < n) {
            
            if (nums1[p1] <= nums2[p2]) {                
                nums1[pi] = nums1[p1];
                p1++;
            }
            else {
                nums1[pi] = nums2[p2];
                p2++;
            }
            pi++;
        }        
        
        while (p1 < m + n) {            
            nums1[pi] = nums1[p1];
            p1++;
            pi++;
        }
        
        while (p2 < n) {            
            nums1[pi] = nums2[p2];
            p2++;
            pi++;
        }
        
    }

    void insert_array(vector<int> &arr, int n) {
        int num;
        for(int i = 0; i < n; i ++) {
            cin >> num;
            arr[i] = num;
        }
    }

    void solve() {

        int n1, n2;
        cin >> n1;
        cin >> n2;
        vector<int> nums1(n1 + n2, 0);
        vector<int> nums2(n2, 0);        
        insert_array(nums1, n1);
        insert_array(nums2, n2);

        merge(nums1, n1, nums2, n2);
        
        for(int i = 0; i < n1 + n2; i++)
            cout << nums1[i] << " ";
        cout << endl;
    }
};

int main() {

    /*
    4 2
    1 4 7 8
    2 5
    */
    
    /*
    1 2 4 5 7 8
    */
    
    Solution soln;
    soln.solve();

    return 0;
}
