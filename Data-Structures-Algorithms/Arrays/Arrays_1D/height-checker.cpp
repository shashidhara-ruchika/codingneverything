/*
https://leetcode.com/explore/learn/card/fun-with-arrays/523/conclusion/3228/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> heights_sorted(heights.size());
        partial_sort_copy(begin(heights), end(heights), begin(heights_sorted), end(heights_sorted));
        
        int count = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(heights[i] != heights_sorted[i])
                count++;
        }
        return count;
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
    1 1 4 2 1 3
    */

    /*
    
    */

    Solution *soln = new Solution;
    vector<int> arr = soln -> inputArr();

    cout << soln -> heightChecker(arr) << endl;

    return 0;
}