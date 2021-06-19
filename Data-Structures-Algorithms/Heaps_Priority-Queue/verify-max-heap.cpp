/*
https://binarysearch.com/problems/Verify-Max-Heap
*/

#include <bits/stdc++.h>

using namespace std;

bool isMaxHeap(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++) {
        if(2*i + 1 < nums.size() && nums[i] < nums[2*i + 1])
            return false;
        if(2*i + 2 < nums.size() && nums[i] < nums[2*i + 2])
            return false;
    }
    return true;
}

/*
Input
5
4 2 3 0 1

Output
true
*/

int main() {
    int n;
    cin >> n;
    vector<int> hp(n, 0);
    for(int i = 0; i < n; i++) 
        cin >> hp[i];    
    cout << isMaxHeap(hp) << endl;
    return 0;
}