/*
https://www.hackerrank.com/challenges/abstract-classes-polymorphism/problem
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer, least recently used
   Node* head; // double linked list head pointer, most recently used
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    private:
    
    public:
    LRUCache(int cap);
    void set(int key, int value);
    int get(int key);
    
};

LRUCache :: LRUCache(int cap) 
{    
    this -> cp = cap;
    this -> head = NULL;
    this -> tail = NULL;
}

void LRUCache :: set(int key, int value) {
    
    if (this -> mp.empty()) {   // no nodes in mp cache
        
        // insert node into DLL
        Node *newnode = new Node(key, value);
        this -> head = newnode;
        this -> tail = newnode;
        // inert node into mp cache
        this -> mp[key] = newnode;
        
        return;
    }
    
    auto mp_it = this -> mp.find(key);
    
    if (mp_it  == mp.end()) { // key not found in mp cache
        
        // remove tail node, if size exceeds
        if (mp.size() == this -> cp) {
            // delete tail node
            this -> tail = this -> tail -> prev;
            mp.erase(this -> tail -> next -> key);  // delete node from mp cache
            delete this -> tail -> next;
            this -> tail -> next = NULL;
        }
        
        // insert node into DLL
        Node *newnode = new Node(key, value);  
        newnode -> next = this -> head;
        this -> head -> prev = newnode;
        this -> head = newnode;
        // insert node 
        mp[key] = newnode;
        
        return;
    }
    
    else { // key found in mp cache
        
        // update value of node of same key in mp cache
        mp_it -> second -> value = value;
        
        if (mp_it -> second == this -> head)    // if cur pos of node is already at the head, don't change pos
            return;
        
        mp_it -> second -> prev -> next = mp_it -> second -> next;
        
        if (mp_it -> second == this -> tail)    // if curr pos of node in DLL is at tail pos in DLL
            this -> tail = this -> tail -> prev;
        else                            // if cur pos of node in DLL is anywhere in between in DLL
            mp_it -> second -> next -> prev = mp_it -> second -> prev;
            
        // insert the node with same key at head pos in DLL
        mp_it -> second -> next = this -> head;
        mp_it -> second -> prev = NULL;
        this -> head -> prev = mp_it -> second;
        this -> head = mp_it -> second;
        
        return;      
    }
    
}

int LRUCache :: get(int key) {
    
    auto mp_it = this -> mp.find(key);
    
    if (mp_it != this -> mp.end()) 
        return mp_it -> second -> value;
    else
        return -1;
}

/*
Sample Input

3 1
set 1 2
get 1
get 2

Sample Output

2
-1
*/

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
