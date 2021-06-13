/*
https://binarysearch.com/problems/Dropped-Sensor-Metric
*/

#include <bits/stdc++.h>

using namespace std;

int droppedSensorMetric(vector<int>& a, vector<int>& b) {
    int ai = 0;
    int bi = 0;
    
    int faulty_num_a = INT_MAX;
    int faulty_num_b = INT_MAX;

    while(ai < a.size() && bi < b.size()) {
        if(a[ai] != b[bi]) {
            if(faulty_num_a == INT_MAX && faulty_num_b == INT_MAX) {
                faulty_num_a = a[ai];
                faulty_num_b = b[bi];
                ai++;
                bi++;
            }
            else {
                if(a[ai] == faulty_num_b) 
                    return faulty_num_a;
                
                else if(b[bi] == faulty_num_a) 
                    return faulty_num_b;
            }
        }
        else {
            ai++;
            bi++;
        }
    }
    return 0;
}

vector<int>& input_vector() {
    int n;
    cin >> n;
    vector<int> vec(n, 0);
    for(int i = 0; i < n; i++) 
        cin >> vec[i];
    return vec;
}

/*
Input
5
5 4 2 1 6
5
5 4 3 2 1

Output
3

Explanation
The accurate metrics come from b = [5, 4, 3, 2, 1].
*/

int main() {
    vector<int> a = input_vector();
    vector<int> b = input_vector();
    cout << droppedSensorMetric(a, b) << endl;
    return 0;
}