/*
https://leetcode.com/problems/min-stack/
*/

# include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    
    // Two stack approach
    // Actual Stack maintains the actual stacks push, pop, top, etc.  Ex: 5 6 0 -1 9 8
    // Min Stack maintains the stack of the min values at the top     Ex: 5 0 -1
    // Min Stack push: only when the x <= minStack.top()
    // Min Stack pop: only when actualStacks ele is popped
    // Min Stack getMin: minStack.top()
    
    stack<int> actualStack;
    stack<int> minStack;
    
    MinStack() {}
    
    void push(int x) {
        
        actualStack.push(x);
        
        if ( minStack.size() == 0 || x <= minStack.top() )
            minStack.push(x);
        
        return;
    }
    
    void pop() {
        
        if (actualStack.empty())
            return;
        
        if (actualStack.top() == minStack.top())
            minStack.pop();
        
        actualStack.pop();
        
        return;
    }
    
    int top() {
        return actualStack.top();        
    }
    
    int getMin() {
        return minStack.top();
    }
};


/*
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
*/

/*
-3
0
2
*/

int main() {
    
    MinStack *obj = new MinStack();

    int num_operations, num;
    cin >> num_operations;
    string op;
    vector<string> operation;
    vector<vector<int>> val;
    for (int i = 0; i < num_operations; i++) {
        cin >> op;
        operation.push_back(op);
    }
    for (int i = 0; i < num_operations; i++) {
        vector<int> val_op;
        if (operation[i] == "push") {
            cin >> num;                
            val_op.push_back(num);
        }                     
        val.push_back(val_op);
    }

    for(int i = 1; i < num_operations; i++) {
        
        if(operation[i] == "push") {
            obj -> push(val[0][0]);
            cout << "null ";
        }
        
        if(operation[i] == "pop") {
            obj -> pop();
            cout << "null ";
        }

        if(operation[i] == "top") 
            cout << obj -> top() << " ";
            
        if(operation[i] == "getMin") 
            cout << obj -> top() << " "; 
    }
    cout << endl;
    
    return 0;
}