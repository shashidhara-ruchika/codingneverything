/*
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solution/
*/

# include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {        
        
        if (head == NULL)
            return NULL;
        
        // add extra root node to make it easier for removal of initial duplicate nodes
        ListNode root = ListNode(0, head);
        ListNode *prev = &root;
        
        while (head != NULL) {
            
            // skip all the duplicates
            if (head -> next != NULL && head -> val == head -> next -> val) {
                
                // move until end of duplicates of the same num
                while (head -> next != NULL && head -> val == head -> next -> val)
                    head = head -> next;
                // assign the prev non duplicate node to the next node by skipping/removing the duplicate nodes
                prev -> next = head -> next;
                
            }
            // if nodes are not duplicate traverse the prev node forward
            else
                prev = prev -> next;
            
            // traverse head forward
            head = head -> next;
        }
        
        // return list from the node after head
        return root.next;
        
    }

    ListNode* insert_list (int n) {

        if (n == 0)
            return NULL;
        
        int num;
        cin >> num;
        ListNode *root = new ListNode(num);
        ListNode *curr = root;
        ListNode *newnode;

        for (int i = 1; i < n; i++) {
            cin >> num;
            newnode = new ListNode(num);
            curr -> next = newnode;
            curr = curr -> next;
        }
        return root;
    }

    void display_list(ListNode *l) {

        while (l != NULL) {
            cout << l -> val << " ";
            l = l -> next;
        }
        cout << endl;
    }
};

int main() {

    /*
    8
    1 1 2 3 3 3 4 5
    */
    
    /*
    1 4 5
    */
    
    Solution *soln = new Solution;
    int n;
    cin >> n;
    ListNode* l = soln -> insert_list(n);

    ListNode* newl = soln -> deleteDuplicates(l);

    soln -> display_list(newl);

    return 0;
}