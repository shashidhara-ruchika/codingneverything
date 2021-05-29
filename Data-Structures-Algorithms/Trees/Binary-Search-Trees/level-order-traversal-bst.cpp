/*
https://www.hackerrank.com/challenges/30-binary-trees/problem
*/

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

using namespace std;	
class Node{
    public:
        int data;
        Node *left,*right;
        Node(int d){
            data=d;
            left=right=NULL;
        }
};
class Solution{
    public:
  		Node* insert(Node* root, int data){
            if(root==NULL){
                return new Node(data);
            }
            else{
                Node* cur;
                if(data<=root->data){
                    cur=insert(root->left,data);
                    root->left=cur;
                }
                else{
                   cur=insert(root->right,data);
                   root->right=cur;
                 }           
           return root;
           }
        }

	void levelOrder(Node * root){
    //Write your code here
        queue<Node*> q;
        
        if (root != NULL) {
            q.push(root);
            
            while(! q.empty()) {
                Node *curr_node = q.front();
                cout << curr_node -> data << " ";
                q.pop();
                
                if (curr_node -> left)
                    q.push(curr_node -> left);
                    
                if (curr_node -> right) 
                    q.push(curr_node -> right);                
            }
        }        
  
	} 

};//End of Solution

/*
Sample Input

6
3
5
4
7
2
1

Sample Output

3 2 5 1 4 7 
*/

int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    myTree.levelOrder(root);
    return 0;
}
