/*
https://leetcode.com/problems/boats-to-save-people/
*/

# include <bits/stdc++.h>

using namespace std;

/*
Intuition:

If the heaviest person can share a boat with the lightest person, then do so. 
Otherwise, the heaviest person can't pair with anyone, so they get their own boat.

The reason this works is because if the lightest person can pair with anyone, 
they might as well pair with the heaviest person.

Algorithm:

Let people[i] to the currently lightest person, and people[j] to the heaviest.

Then, as described above, if the heaviest person can share a boat with the 
lightest person (if people[j] + people[i] <= limit) then do so; 
otherwise, the heaviest person sits in their own boat.
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int l = 0, r = people.size() - 1, minBoats = 0;
        
        while ( l <= r ) {
            
            minBoats++;
            
            if ( people[l] + people[r] <= limit )
                l++;
            
            r--;
        }
        
        return minBoats;
        
    }

    vector<int> inputArr() {
        int n, num;
        cin >> n;
        vector<int> arr;
        while ( n-- > 0 ) {
            cin >> num;
            arr.push_back(num);
        }
        return arr;
    }
};

int main () {

    /*
    4
    3 1 2 2
    3
    */

    // (1,2), (2), (3)
  
    /*
    3
    */

    Solution *soln = new Solution();
    vector<int> arr = soln -> inputArr();
    int limit;
    cin >> limit;
    cout << soln -> numRescueBoats(arr, limit) << endl;

    return 0;
}
