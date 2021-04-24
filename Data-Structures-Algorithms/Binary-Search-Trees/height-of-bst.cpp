/*
https://www.hackerrank.com/challenges/30-binary-search-trees/problem
*/

#include <iostream>
#include <cstddef>

using namespace std;	

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

		int getHeight(Node* root){
          //Write your code here
            if (root == NULL)
                return -1;                
            int left_height = this -> getHeight(root -> left);
            int right_height = this -> getHeight(root -> right);
            return 1 + max(left_height, right_height);
        }

}; //End of Solution

/*
Sample Input

7
3
5
2
1
4
6
7

Sample Output

3
*/

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}
    
       
            
        