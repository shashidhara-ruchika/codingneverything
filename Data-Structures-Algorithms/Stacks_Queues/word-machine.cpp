/*
https://binarysearch.com/problems/Word-Machine
*/

#include <bits/stdc++.h>
using namespace std;

int top_of_stack_word_machine(vector<string>& ops) {
    stack<int> stk;

    for(auto &op : ops) {
        
        if (op == "POP") {
            if (!stk.empty())
                stk.pop();
            else
                return -1;
        }

        else if (op == "DUP") {
            if (!stk.empty()) 
                stk.push(stk.top());
            else
                return -1;
        }

        else if (op == "+") {
            
            int sum = INT_MIN;

            if (!stk.empty()) {
                sum = stk.top();
                stk.pop();

                if (!stk.empty()) {
                    sum += stk.top();
                    stk.pop();
                }
                else
                    return -1;
            }
            else 
                return -1;
            
            if (sum != INT_MIN)
                stk.push(sum);
            else
                return -1;
        }

        else if (op == "-") {
            
            int sum = INT_MIN;

            if (!stk.empty()) {
                sum = stk.top();
                stk.pop();

                if (!stk.empty()) {
                    sum -= stk.top();
                    stk.pop();
                }
                else
                    return -1;
            }
            else 
                return -1;
            
            if (sum != INT_MIN)
                stk.push(sum);
            else
                return -1;
        }

        else {
            stk.push(stoi(op));
        }
    }

    if (!stk.empty())
        return stk.top();
    else
        return -1;
}

/*
Input
5
1
5
DUP
3
-

Output
-2

Explanation
Following the operations:
We push 1 into the stack: [1]
We push 5 into the stack: [1, 5]
We duplicate the top element: [1, 5, 5]
We push 3 into the stack: [1, 5, 5, 3]
We pop 3 and 5 and push their difference 3 - 5: [1, 5, -2]
We return the top element which is -2


Input
1
+

Output
-1

Explanation
There's no elements in the stack so this is invalid.
*/

int main() {
    int n;
    cin >> n;
    vector<string> v(n, "");
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << top_of_stack_word_machine(v) << endl;
    return 0;
}