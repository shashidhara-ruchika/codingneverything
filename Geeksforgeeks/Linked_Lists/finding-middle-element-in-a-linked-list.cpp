/*
https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1/
*/

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
} 
/* Function to get the middle of the linked list*/
int getMiddle(Node *head);
int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int data;
		cin>>data;
		struct Node *head = new Node(data);
		struct Node *tail = head;
		for (int i = 0; i < n-1; ++i)
		{
			cin>>data;
			tail->next = new Node(data);
			tail = tail->next;
		}
		cout<<getMiddle(head)<<endl;
	}
	return 0; 
} 

// } Driver Code Ends


/* Link list Node 
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head) {
    
    if (head == NULL)
        return -1;
    
    Node* fast = head;
    Node* slow = head;
    
    while (fast && fast-> next) {
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    return slow -> data;
}

/*
int findLen(Node *head) {
    
    int len = 0;
    Node* temp = head;
    while (temp) {
        len++;
        temp = temp -> next;
    }
    return len;
}

int getMiddle(Node *head)
{
   // Your code here
   int mid = findLen(head)/2;
   if (head == NULL)
    return -1;
  
   Node *temp = head;
   
   while (mid > 0) {
       temp = temp -> next;
       mid --;
   }
    
    return temp -> data;
   
}
*/
