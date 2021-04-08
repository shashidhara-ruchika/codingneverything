/*
https://leetcode.com/problems/flipping-an-image/
*/

/*
1 1 0
1 0 1
0 0 0
    
1 0 0
0 1 0
1 1 1    
    
    
1 1 0 0
1 0 0 1
0 1 1 1
1 0 1 0
    
1 1 0 0
0 1 1 0
0 1 1 1
1 0 1 0    
    
0 0 => 0 0 => 1 1 => inverts bits
0 1 => 1 0 => 0 1 => stays the same
1 0 => 0 1 => 1 0 => stays the same
1 1 => 1 1 => 0 0 => inverts bits

0 => 0 => 1 => inverts bits
1 => 1 => 0 => inverts bits

0 ^ 1 = 1
1 ^ 1 = 0
 

4/2 = 2
3/2 = 1

4    
0 1 4-1-1 4-0-1
0 1 2     3    
    
5
0 1 2 5-1-1 5-0-1
0 1 2 3     4  
*/

# include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
       
        int mat_size = A.size();
        
        for (int row = 0; row < mat_size; row++) {
            
            for (int col = 0; col < mat_size/2; col++) {
                
                // only if bits are similar, bits are flipped & inverted
                if (A[row][col] == A[row][mat_size - col - 1]) {
                    
                    /*
                    if (A[row][col]) {
                        A[row][col] = 0;
                        A[row][mat_size - col - 1] = 0;
                    }
                    else {
                        A[row][col] = 1; 
                        A[row][mat_size - col - 1] = 1;
                    }  
                    */
                    
                    A[row][col] ^= 1;
                    A[row][mat_size - col - 1] ^= 1;
                    
                }
                
            }
            
            // odd size matrix, median ele should only be inverted
            if (mat_size % 2) {
                /*
                if (A[row][mat_size / 2] == 1)
                    A[row][mat_size / 2] = 0;
                else
                    A[row][mat_size / 2] = 1;
                */
                A[row][mat_size / 2] ^= 1;
            }
            
        }
        return A;
    }

    vector<vector<int>> inputMat() {
        int mat_size, num;
        cin >> mat_size;

        vector<vector<int>> mat;
        
        for(int i = 0; i < mat_size; i++) {
            vector<int> row;
            for(int j = 0; j < mat_size; j++) {
                cin >> num;
                row.push_back(num);
            }
            mat.push_back(row);
        }

        return mat;
    }
    
    void displayMat(vector<vector<int>> mat) {
        
        int mat_size = mat.size();
        for(int i = 0; i < mat_size; i++) {
            for(int j = 0; j < mat_size; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    /*
    3
    1 1 0
    1 0 1
    0 0 0
    */

    /*    
    1 0 0
    0 1 0
    1 1 1
    */

    Solution *soln = new Solution;
    vector<vector<int>> mat = soln -> inputMat();
    soln -> displayMat(mat);

    return 0;

}