/*
https://binarysearch.com/problems/Range-Query-on-a-List
*/

#include <bits/stdc++.h>

using namespace std;

class RangeSum {
  
private:
    vector<int> uptosum;
    
public:

    RangeSum(vector<int>& nums) {

        this -> uptosum.resize(nums.size(), 0);
        
        this -> uptosum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) 
            this -> uptosum[i] += this -> uptosum[i - 1] + nums[i];
        
    }

    int total(int i, int j) {
        
        int range_sum = 0;
        
        if (i >= 0 && i < this -> uptosum.size() && 
            j > 0 && j <= this -> uptosum.size() 
            && i <= j) {

                range_sum += uptosum[j - 1];
                
                if(i > 0)
                    range_sum -= uptosum[i - 1];            
        }
        
        return range_sum;
    }
};


vector<int>& input_nums() {
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) 
      cin >> nums[i];
    return nums;
}

/*
Input
6
1 2 5 0 3 7
2
0 3
1 5

Output
8
10

Explanation
r = RangeSum([1,2,5,0,3,7])
r.total(0, 3) == 8 # sum([1, 2, 5])
r.total(1, 5) == 10 # sum([2, 5, 0, 3])
*/

int main() {
    vector<int> v = input_nums();
    int q, l, r;
    cin >> q;
    RangeSum rs(v); // Calc range sum of [l, r)
    while(q-- > 0) {
        cin >> l >> r;
        cout << rs.total(l, r) << endl;
    }
    return 0;
}

