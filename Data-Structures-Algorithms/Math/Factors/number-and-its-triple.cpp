/*
https://binarysearch.com/problems/A-Number-and-Its-Triple
*/

#include <bits/stdc++.h>
using namespace std;

bool isTriplePresent(vector<int>& nums) {
    
    if(nums.size() < 2)
        return false;

    unordered_set<int> num_set;
    int count0 = 0;

    for(auto n : nums) {

        if (num_set.find(n*3) != num_set.end() ||
            (n%3 == 0 && num_set.find(n/3) != num_set.end()) ||
            count0 > 1 )
            return true;        
        
        if(n == 0)
            count0++;
        else 
            num_set.insert(n);
        
    }
        
    int n = nums[nums.size() - 1];
    return  num_set.find(n*3) != num_set.end() ||
            (n%3 != 0 && num_set.find(n/3) != num_set.end()) ||
            count0 > 1 ;
}

/*
Input
6
2 3 3 6 7 10 

Output
1
*/

int main() {
    int n, num;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> num;
        nums[i] = num;
    }
    cout << isTriplePresent(nums) << endl;
    return 0;
}