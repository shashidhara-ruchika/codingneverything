/*
https://binarysearch.com/problems/Complete-an-Arithmetic-Sequence
*/

#include <bits/stdc++.h>
using namespace std;

int ap_missing_num(vector<int>& nums) {
    float d = (float)(nums[nums.size() - 1] - nums[0]) / (float)nums.size();
    if (d == 0)
        return nums[0];
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] != nums[0] + d * i)
            return nums[0] + d * i;            
    }
    return 0;
}


/*
4
1 3 5 9

2
1 1

3
9 6 0
*/

/*
7
1
3
*/

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << ap_missing_num(v) << endl;
    return 0;
}