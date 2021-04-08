/*
https://leetcode.com/problems/minimum-index-sum-of-two-lists/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        
        unordered_map <string, int> hashmap;
        
        for (int i = 0; i < list1.size(); i++) 
            hashmap[list1[i]] = i;
        
        int least_index_sum = INT_MAX;
        
        vector<string> commRest;
        
        for (int i = 0; i < list2.size(); i++) {
            
            if (hashmap.find(list2[i]) != hashmap.end()) {
                
                int curr_index_sum = i + hashmap[list2[i]];
                
                if (curr_index_sum == least_index_sum)
                    commRest.push_back(list2[i]);
                
                else if (curr_index_sum < least_index_sum) {
                    commRest.clear();
                    commRest.push_back(list2[i]);
                    least_index_sum = curr_index_sum;
                }
                    
            }
        }
        
        return commRest;
    }

    vector<string> findRestaurant_complex(vector<string>& list1, vector<string>& list2) {
        
        unordered_map<string, pair<int, bool>> allRest;
        
        for (int i = 0; i < list1.size(); i++)
            allRest[list1[i]] = {i, false};
        
        for (int i = 0; i < list2.size(); i++) {
            if (allRest.find(list2[i]) == allRest.end())    // not present
                allRest[list2[i]] = {i, false};
            else {                                          // present
                allRest[list2[i]].first += i;
                allRest[list2[i]].second = true;
            }
        }
        
        map <int, vector<string>> commonRest;
        int least_index_sum = INT_MAX;
        
        for (auto kvp: allRest) {
            
            if (kvp.second.second == true) {

                if (commonRest.find(kvp.second.first) == commonRest.end())  // not present
                    commonRest[kvp.second.first] = {kvp.first};
                else                                                        // present
                    commonRest[kvp.second.first].push_back(kvp.first);
                
                least_index_sum = min(kvp.second.first, least_index_sum);
            }
        }
        
        return commonRest[least_index_sum];
        
    }

    vector<string> inputVector(int n) {
        string s;
        vector<string> svec;
        while(n--) {
            getline(cin, s);
            svec.push_back(s);
        }
        return svec;
    }

    void displayVector(vector<string> svec) {
        for (auto s : svec) 
            cout << s << " ";
        cout << endl;
    }
};

int main() {
    /*
    5
    Shogun 
    KNN
    Tapioca Express
    Burger King
    KFC
    4 
    KNN
    Shogun 
    KFC
    Burger King
    */

    // output intersected array need not be in the same order
    /*
    Shogun KNN
    KNN Shogun
    */

    int n1, n2;
    Solution *soln = new Solution();

    cin >> n1;
    vector<string> a1 = soln -> inputVector(n1);

    cin >> n2;
    vector<string> a2 = soln -> inputVector(n2);

    vector<string> intersect1 = soln -> findRestaurant(a1, a2);
    soln -> displayVector(intersect1);

    vector<string> intersect2 = soln -> findRestaurant_complex(a1, a2);
    soln -> displayVector(intersect2);

    return 0;
}