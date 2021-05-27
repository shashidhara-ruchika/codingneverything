/*
https://binarysearch.com/problems/Longest-Anagram-Subsequence
*/

# include <bits/stdc++.h>

using namespace std;

int getLongestAnagramSubsequence(string a, string b) {
    vector<int> freq_a(26, 0);
    vector<int> freq_b(26, 0);
    for(auto ac : a) {
        freq_a[ac - 'a']++;
    }
    for(auto bc : b) {
        freq_b[bc - 'a']++;
    }
    int count = 0;
    for (int i = 0; i < 26; i++) {
        count += min(freq_a[i], freq_b[i]);
    }
    return count;
}

/*
Input
afbc
cxba

Output
3

Explanation
"abc" is a subsequence in "afbc"
"cba" is a subsequence in "cxba"
And abc and cba are anagrams of each other.
*/

int main() {
    string a, b;
    cin >> a >> b;
    cout << getLongestAnagramSubsequence(a, b) << endl;
    return 0;
}