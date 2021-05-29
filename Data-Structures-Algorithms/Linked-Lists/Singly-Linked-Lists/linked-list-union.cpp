/*
https://binarysearch.com/problems/Linked-List-Union
*/

/*
Given two sorted linked lists ll0, and ll1, 
return a new sorted linked list containing the union of the two lists.
*/

#include <bits/stdc++.h>
using namespace std;

class LLNode {
    public:
        int val;
        LLNode *next;
};

class LLUnion {
    private:
        LLNode* ll0;
        LLNode* ll1;
        void insert_list(LLNode *list);

    public:
        LLUnion();
        LLNode *get_union();
        void print_list(LLNode *list);
};

LLUnion :: LLUnion () {
    insert_list(this -> ll0);
    insert_list(this -> ll1);
}

void LLUnion :: insert_list(LLNode *list) {
    int n;
    if (n == 0)
        return;

    int num;
    cin >> num;
    list -> val = num;
    n--;
    if(n == 1)
        return;

    while(n-- > 0) {
        cin >> num;
        LLNode *newnode = new LLNode();
        newnode -> val = num;
        list -> next = newnode;
        list = list -> next;
    }
}

void LLUnion :: print_list(LLNode *list) {
    while( !list ) {
        cout << list -> val << " ";
    }
    cout << endl;
}

LLNode* LLUnion :: get_union() {

    LLNode *l = new LLNode();
    l -> val = -1;
    LLNode *newl = l;

    if ( ! this -> ll0 ) {
        return this -> ll1;
    }

    if ( ! this -> ll1 ) {
        return this -> ll0;
    }
    
    while ( this -> ll0 && this -> ll1 ) {
        if (this -> ll0 -> val < this -> ll1 -> val) {
            
            if (newl -> val != this -> ll0 -> val) {
                LLNode *newnode = new LLNode();
                newnode -> val = this -> ll0 -> val;
                newl -> next = newnode;
                newl = newl -> next;
            }
            
            this -> ll0 = this -> ll0 -> next;
        }
        else {
            
            if (newl -> val != this -> ll1 -> val) {
                LLNode *newnode = new LLNode();
                newnode -> val = this -> ll1 -> val;
                newl -> next = newnode;
                newl = newl -> next;
            }
            
            this -> ll1 = this -> ll1 -> next;
        }
    }

    while (this -> ll0) {
        
        if (newl -> val != this -> ll0 -> val) {
            LLNode *newnode = new LLNode();
            newnode -> val = this -> ll0 -> val;
            newl -> next = newnode;
            newl = newl -> next;
        }
        
        this -> ll0 = this -> ll0 -> next;
    }

    while (this -> ll1) {
        if (newl -> val != this -> ll1 -> val) {
            LLNode *newnode = new LLNode();
            newnode -> val = this -> ll1 -> val;
            newl -> next = newnode;
            newl = newl -> next;
        }
        
        this -> ll1 = this -> ll1 -> next;
    }

    return l -> next;
}

/*
Input
3
1 3 4
3
2 3 4

Output
1 2 3 4
*/

int main() {
    
    LLUnion* union_ptr = new LLUnion();
    LLNode* union_list = union_ptr -> get_union();
    union_ptr -> print_list(union_list);

    return 0;
}