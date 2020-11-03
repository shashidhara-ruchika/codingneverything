/*
https://leetcode.com/problems/longest-common-prefix/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {

public:

    string commonPrefix(string& s1, string& s2) {
        
        int s1_len = s1.length();
        int s2_len = s2.length();
        
        int min_len = min(s1_len, s2_len);
        int i = 0;
        
        while (i < min_len) {
            if(s1[i] != s2[i]) {
                break;
            }
            i++;
        }
        
        return s1.substr(0,i);
    }
    
    string getLongestCommonPrefix(vector<string>& strs, int l, int r) {
        
        if(l == r) {
            return strs[l];
        }
        else {
            int mid = (l + r)/2;
            string left_lcp = getLongestCommonPrefix(strs, l, mid);
            string right_lcp = getLongestCommonPrefix(strs, mid + 1, r);
            return commonPrefix(left_lcp, right_lcp);
        }
    }  

    // divide & conquer method
    string longestCommonPrefix_div_conq(vector<string>& strs) {
        
        if (strs.size() == 0)
            return "";
        return getLongestCommonPrefix(strs, 0, strs.size() - 1);        
    }

    // normal character equal check
    string longestCommonPrefix(vector<string>& strs) {
        
        int strs_len = strs.size(), i = 1;
        
        if (strs_len == 0)
            return "";
        
        string lcp = strs[0];
        
        while (i < strs_len) {
            
            lcp = commonPrefix(lcp, strs[i]);            
            i++;
            
        }
        
        return lcp;  

    }

    vector<string> inputVecStrings() {
        int n;
        string s;
        vector<string> strs;

        cin >> n;
        while(n-- > 0) {
            cin >> s;
            strs.push_back(s);
        }
        return strs;
    }   
};

int main() {

    /*
    3
    flower flow flight
    2
    dog cat
    */

    /*
    fl
    
    */
       
    Solution *soln = new Solution;
    vector<string> strarr1 = soln -> inputVecStrings();
    cout << soln -> longestCommonPrefix(strarr1) << endl;

    Solution *soln_div_conq = new Solution;
    vector<string> strarr2 = soln -> inputVecStrings();
    cout << soln_div_conq -> longestCommonPrefix_div_conq(strarr2) << endl;
    
    return 0;
}