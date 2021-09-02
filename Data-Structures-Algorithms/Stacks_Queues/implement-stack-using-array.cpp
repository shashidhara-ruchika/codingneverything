// https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1

/*
Input: 
pop()
push(4)
push(5)
pop()

Output: -1, 5

Your Task:
You are required to complete two methods push() and pop(). 
The push() method takes one argument, an integer 'x' to be pushed into the stack and pop() 
which returns an integer present at the top and popped out from the stack. 
If the stack is empty then return -1 from the pop() method.

Expected Time Complexity : O(1) for both push() and pop().
Expected Auixilliary Space : O(1) for both push() and pop().
*/

#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}
// } Driver Code Ends



//Function to push an integer into the stack.
void MyStack :: push(int x)
{
    // Your Code
    
    if (top < 1000)
        arr[++top] = x;
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    // Your Code       
    
    return (top > -1) ? arr[top--] : -1;
}
