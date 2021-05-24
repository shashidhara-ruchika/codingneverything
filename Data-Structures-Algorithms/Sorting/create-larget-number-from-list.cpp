/*
https://binarysearch.com/problems/Create-Largest-Number-From-a-List
*/

# include <bits/stdc++.h>

using namespace std;

bool str_int_compare(int n1, int n2) {
   
    stringstream ss1;
    ss1 << n1 << n2;

    stringstream ss2;
    ss2 << n2 << n1;

    return ss1.str() > ss2.str();
}

string get_largest_num(vector<int>& nums) {
    sort(nums.begin(), nums.end(), str_int_compare);           
    
    stringstream large_num;
    for (auto n : nums) {
        //cout << n << " ";
        large_num << n;
    }
    //cout << endl;
    return large_num.str();
}

vector<int> input_vector() {
    int n, num;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> num;
        v[i] = num;
    }
    return v;    
}

/*
Input
4
10 7 76 415

Output
77641510
*/

int main() {
    vector<int> nums = input_vector();
    cout << get_largest_num(nums) << endl;
    return 0;
}

