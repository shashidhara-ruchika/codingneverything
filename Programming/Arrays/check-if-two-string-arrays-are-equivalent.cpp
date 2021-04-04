/*
https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int wordi1 = 0, wordi2 = 0, letteri1 = 0, letteri2 = 0;
        
        while ( wordi1 < word1.size() && 
                wordi2 < word2.size() && 
                letteri1 < word1[wordi1].size() && 
                letteri2 < word2[wordi2].size()      ) {
            
                    if (word1[wordi1][letteri1] != word2[wordi2][letteri2])
                        return false;

                    letteri1++;
                    letteri2++;

                    if (letteri1 == word1[wordi1].size()) {
                        letteri1 = 0;
                        wordi1++;
                    }
            
                    if (letteri2 == word2[wordi2].size()) {
                        letteri2 = 0;
                        wordi2++;
                    }
        }        
            
        return letteri1 == letteri2;
    }

    bool arrayStringsAreEqualConcat(vector<string>& word1, vector<string>& word2) {
        
        string s1, s2;
        
        for (int i = 0; i < word1.size(); i++)
            s1 += word1[i];
        
        for (int i = 0; i < word2.size(); i++)
            s2 += word2[i];
        
        return s1 == s2;        
    }

    vector<string> inputStringArr() {
        int n;
        string s;
        vector<string> vs;
        cin >> n;
        while (n-- > 0) {
            cin >> s;
            vs.push_back(s);
        }
        return vs;
    }
};

int main() {

    /*
    3
    abc d defg
    1
    abcddefg
    4
    as df gh jk
    2
    asdf gh
    */

    /*
    1
    0
    */

    Solution *soln = new Solution;
    vector<string> vs1word1 = soln -> inputStringArr();
    vector<string> vs1word2 = soln -> inputStringArr();
    cout << soln -> arrayStringsAreEqual(vs1word1, vs1word2) << endl;

    Solution *solncc = new Solution;
    vector<string> vs2word1 = solncc -> inputStringArr();
    vector<string> vs2word2 = solncc -> inputStringArr();
    cout << solncc -> arrayStringsAreEqualConcat(vs2word1, vs2word2) << endl;

    return 0;
}

