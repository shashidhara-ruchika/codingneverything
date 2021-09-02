// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}



 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;
*/


class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    /*
    Swap the data of the next node with the current node until we reach the last node
    At the last node, free & set curr -> next to NULL
    */
    void deleteNode(Node *del)
    {
       // Your code here
       Node *ptr_node = del;
       
       while (ptr_node -> next -> next != NULL) {
            
            ptr_node -> data = ptr_node -> next -> data;
            
            ptr_node = ptr_node -> next;
       }
       
       ptr_node -> data = ptr_node -> next -> data;
       
       Node *last_node = ptr_node -> next;
       free(last_node);
       
       ptr_node -> next = NULL;
       
    }

};

/*
Input:
4
10 20 4 30
20

Output: 
10 4 30

Explanation: 
After deleting 20 from the linked list, 
we have remaining nodes as 10, 4 and 30.
*/

// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;
    
    scanf("%d",&t);
    while(t--)
    {
        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);
        Solution ob;
        if (del != NULL && del->next != NULL)
        {
            ob.deleteNode(del);
        }
        printList(head);
    }
    return(0);
}


  // } Driver Code Ends