/*
https://www.codechef.com/LRNDSA02/problems/INPSTFIX
*/

/*

examples

((A+B)*D)^(E-F)				AB+D*EF-^

A+(B*C-(D/E^F)*G)*H			ABC*DEF^/G*-H*+

*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int precedence(char &op) {
    if(op == '^')
        return 3;
    else if(op == '/' or op == '*')
        return 2;
    else if(op == '+' or op == '-')
        return 1;
    else
        return -1;
}

int main() {
	int T;
	cin >> T;
	while(T-- > 0) {
	    int N;
	    cin >> N;
	    stack<char> stck;
	    char sym;
	    while(N-- > 0) {
	        cin >> sym;
	        if(precedence(sym) == -1) {         //if sym is (, ), A-Z
	            if(sym == '(')                  //if sym is (, push it to stack
	                stck.push(sym);             
	            else if(sym == ')') {           //if sym is ), until a ( is reached, pop & print the operators, pop ) at the end
	                while(stck.top() != '(') {  
	                    cout << stck.top();
	                    stck.pop();
	                }
	                stck.pop();                 
	            }
	            else                            //if sym is A-Z, print it
	                cout << sym;
	        } 
	        else {                              //if sym is an operator: ^, /, *, +, -, until a the top of stack operators precedence is lte sym's precedence, pop & print the operators, push the new sym to the stack 
	            while(!stck.empty() && precedence(sym) <= precedence(stck.top())) {
	                cout << stck.top();
	                stck.pop();
	            }
	            stck.push(sym);
	        }
	    }
	    while(!stck.empty()) {                  //pop & print the remaining sym operators still present in the stack
	        cout << stck.top();
	        stck.pop();
	    }
	    cout << endl;
	}
	return 0;
}
