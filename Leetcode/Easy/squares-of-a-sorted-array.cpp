/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:    
    vector<int> sortedSquares_end_pointers(vector<int>& A) {
        
        int l = 0, r = A.size() - 1, i = A.size() - 1;
        
        vector<int> sorted_array_squared(A.size());
        
        while (l <= r) {
            if (abs(A[l]) <= abs(A[r])) {
                sorted_array_squared[i--] = A[r] * A[r]; 
                r--;
            }
            else {
                sorted_array_squared[i--] = A[l] * A[l];
                l++;
            }
            //i++;
        }
        return sorted_array_squared;
    }
    
    vector<int> sortedSquares_mid_pointers(vector<int>& A) {
        
        vector<int> sorted_array_squared;
        auto pos_it = lower_bound(A.begin(), A.end(), 0);
        auto neg_it = pos_it - 1;
        
        // [1 2 3 4 5]
        //  ^          ^
        //  |          |
        //  |          |
        //  begin      end
        
        while (pos_it < A.end() && neg_it >= A.begin()) {
            if (*pos_it == abs(*neg_it)) {
                sorted_array_squared.push_back((*pos_it) * (*pos_it));
                sorted_array_squared.push_back((*neg_it) * (*neg_it));
                pos_it++;
                neg_it--;
            }
            else if (*pos_it < abs(*neg_it)) {
                sorted_array_squared.push_back((*pos_it) * (*pos_it));
                pos_it++;
            }
            else {
                sorted_array_squared.push_back((*neg_it) * (*neg_it));
                *neg_it--;
            }            
        }
        
        while(pos_it < A.end()) {
            sorted_array_squared.push_back((*pos_it) * (*pos_it));
            pos_it++;
        }
        
        while(neg_it >= A.begin()) {
            sorted_array_squared.push_back((*neg_it) * (*neg_it));
            neg_it--;
        }
            
        return sorted_array_squared;
        
    }

    void displayArr(vector<int> A) {
        for(auto x: A) 
            cout << x << " ";
        cout << endl;
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
    6
    -10 -7 -1 0 1 10
    3
    -9 -8 -1
    */

    /*
    0 1 1 49 100 100
    1 64 81
    */

    Solution *soln1 = new Solution;
    Solution *soln2 = new Solution;
    
    vector<int> arr1 = soln1 -> inputArr();
    vector<int> sortedsq1 = soln1 -> sortedSquares_mid_pointers(arr1);
    soln1 -> displayArr(sortedsq1);
    
    vector<int> arr2 = soln2 -> inputArr();
    vector<int> sortedsq2 = soln2 -> sortedSquares_mid_pointers(arr2);
    soln1 -> displayArr(sortedsq2);

    return 0;
}