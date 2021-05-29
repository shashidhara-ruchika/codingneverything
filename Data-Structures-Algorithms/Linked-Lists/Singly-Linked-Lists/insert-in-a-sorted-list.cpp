/*
https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1/
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

Node *sortedInsert(struct Node *head, int data);

void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data <<" "; 
		node = node->next; 
	}  
	cout<<"\n";
}

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
		
		int k;
		cin>>k;
		
		head = sortedInsert(head,k);
		printList(head); 
	}
	return 0; 
} 
// } Driver Code Ends


/*
structure of the node of the list is as
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

// Should return head of the modified linked list
Node *sortedInsert(struct Node* head, int data) {
    // Code here
    Node *new_node = new Node(data);
    
    // insert at begining 
    if (head == NULL || (new_node -> data < head -> data)) {
        new_node -> next = head;
        head = new_node;
    }
    
    // insert at middle or end
    else {
    
        Node *prev = head;
        while (prev -> next && new_node -> data > prev -> next -> data) {
            prev = prev -> next;
        }
        
        new_node -> next = prev -> next;
        prev -> next = new_node;
        
    }
    
    return head;
}
