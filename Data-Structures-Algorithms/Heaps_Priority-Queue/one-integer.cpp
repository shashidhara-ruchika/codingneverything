/*
https://binarysearch.com/problems/One-Integer
*/

#include <bits/stdc++.h>

using namespace std;

/*
You are given a list of integers nums.
You can reduce the length of nums by taking any two integers, 
removing them, and appending their sum to the end. 
The cost of doing this is the sum of the two integers you removed.
Return the minimum total cost of reducing nums to one integer.
*/

int ret_one_sum(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int> > pq;

    for(auto n : nums) 
        pq.push(n);
    
    int sum = 0;

    while(pq.size() >= 2) {
        int s1 = pq.top();
        pq.pop();
        int s2 = pq.top();
        pq.pop();
        int ns = s1 + s2;
        sum += ns;
        pq.push(ns);
    }

    return sum;
    
}

/*
5
1 2 3 4 5
*/

/*
33
*/

int main() {
    int n, num;
    cin >> n;
    vector<int> vec;
    while(n--  > 0) {
        cin >> num;
        vec.push_back(num);
    }
    cout << ret_one_sum(vec) << endl;
    return 0;
}