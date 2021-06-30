/*
https://leetcode.com/problems/beautiful-arrangement/
*/

# include <bits/stdc++.h>

using namespace std;

/*
The idea behind this approach is simple. We try to create all the permutations of numbers from 1 to N. We can fix one number at a particular position and check for the divisibility criteria of that number at the particular position. But, we need to keep a track of the numbers which have already been considered earlier so that they aren't reconsidered while generating the permutations. If the current number doesn't satisfy the divisibility criteria, we can leave all the permutations that can be generated with that number at the particular position. This helps to prune the search space of the permutations to a great extent. We do so by trying to place each of the numbers at each position.

We make use of a visited array of size NN. Here, visited[i]visited[i] refers to the i^{th}i 
th
  number being already placed/not placed in the array being formed till now(True indicates that the number has already been placed).

We make use of a calculate function, which puts all the numbers pending numbers from 1 to N(i.e. not placed till now in the array), indicated by a FalseFalse at the corresponding visited[i]visited[i] position, and tries to create all the permutations with those numbers starting from the pospos index onwards in the current array. While putting the pos^{th}pos 
th
  number, we check whether the i^{th}i 
th
  number satisfies the divisibility criteria on the go i.e. we continue forward with creating the permutations with the number ii at the pos^{th}pos 
th
  position only if the number ii and pospos satisfy the given criteria. Otherwise, we continue with putting the next numbers at the same position and keep on generating the permutations.
*/

class Solution {
public:
    int count = 0;
    
    int countArrangement(int n) {
        
        vector<bool> visited(n + 1, false);
        
        calc(n, 1, visited);
        
        return count;
            
    }
    
    void calc(int n, int pos, vector<bool> visited) {
        
        if (pos > n)
            count++;
        
        for (int i = 1; i <= n; i++) {
            
            if ( !visited[i] && (pos % i == 0 || i % pos == 0)) {
                
                visited[i] = true;
                
                calc(n, pos + 1, visited);
                
                visited[i] = false;
            }
            
        }
    }
};

int main() {
    /*
    4
    */

    // Possible solutions: 1234, 1432, 2134, 2431, 3124, 3421, 4123, 4321

    /*
    8
    */

    /*
    41
    */
     
    Solution *soln = new Solution;
    int n;
    cin >> n;
    cout << soln -> countArrangement(n) << endl;

    return 0;
}