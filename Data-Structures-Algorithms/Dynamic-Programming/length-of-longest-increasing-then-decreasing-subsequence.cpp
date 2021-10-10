// https://www.interviewbit.com/problems/length-of-longest-subsequence/

#include<bits/stdc++.h>
using namespace std;

class Solution {

public: int longestSubsequenceLength(const vector<int> &A) {

    vector<int> dpinc(A.size(), 1);
    vector<int> dpdec(A.size(), 1);

    for (int i = 1; i < A.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && dpinc[i] < dpinc[j] + 1)
                dpinc[i] = dpinc[j] + 1;
        }
    }

    for (int i = A.size() - 2; i >= 0; i--) {
        for (int j = A.size() - 1; j > i; j--) {
            if (A[i] > A[j] && dpdec[i] < dpdec[j] + 1)
                dpdec[i] = dpdec[j] + 1;
        }
    }

    int seqlen = 0;

    for (int i = 0; i < A.size(); i++) {
        seqlen = max(dpinc[i] + dpdec[i] - 1, seqlen);
    }

    return seqlen;
}

};

/*
Input:
9
1 11 2 4 10 4 5 2 1

Output:
7

Example:
array 1 11 2 4 10 4 5 2 1
dpinc 1  2 1 2  3 1 1 1 1
dpdec 1  2 1 1  5 4 3 2 1
 */

int main() {
    Solution *s1 = new Solution();
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << s1 -> longestSubsequenceLength(a) << endl;
    return 0;

}