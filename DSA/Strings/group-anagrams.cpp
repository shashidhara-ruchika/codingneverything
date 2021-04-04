/*
https://leetcode.com/problems/group-anagrams/
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string retCharCount(string s) {
        
        vector<int> v(26, 0);
        
        for(int i = 0; i < s.length(); i++) {
            v[(int)(s[i] - 'a')]++;
        }
        
        string vs ="";
        for(int i = 0; i < 26; i++) {
            vs += v[i];
        }
        return vs;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagrams;
        
        for(int i = 0; i < strs.size(); i++) {
            
            string countchar = retCharCount(strs[i]);
            
            if(anagrams.find(countchar) == anagrams.end()) {
                anagrams[countchar] = {strs[i]};
            }
            else {
                anagrams[countchar].push_back(strs[i]);
            }
            
        }
        
        vector<vector<string>> grouped_anagrams;
        
        for (auto group: anagrams) {
            grouped_anagrams.push_back(group.second);
        }
        
        return grouped_anagrams;
    }

    void printVec(vector<string>& strs) {
        for (auto s: strs) 
            cout << s << " ";
        cout << endl;
    }

    vector<string> inputVec(int n) {
        vector<string> strs;
        string s;
        while (n-- > 0) {
            cin >> s;
            strs.push_back(s);
        }
        return strs;
    }
}; 

int main() {
    
    /*
    6
    eat tea tan ate nat bat
    */

    /*
    bat
    tan nat
    eat tea ate
    */
    
    Solution *soln = new Solution;
    int n;
    cin >> n;
    vector<string> strs = soln -> inputVec(n);

    vector<vector<string>> grouped_anagrams = soln -> groupAnagrams(strs);

    for (auto group: grouped_anagrams) {
        soln -> printVec(group);
    }
    cout << endl;

    return 0;
}