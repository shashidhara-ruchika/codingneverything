/*
https://www.hackerrank.com/challenges/30-queues-stacks/problem
*/

#include <iostream>

using namespace std;

class Solution {
    //Write your code here
    private:
    char stack[1000000];
    char queue[1000000];
    int stack_len = 0;
    int queue_len = 0;
    int stack_ptr = 0;
    int queue_ptr = 0;
    
    public:
    //Stack Operations
    void pushCharacter(char ch);
    char popCharacter();
    //Queue Operations
    void enqueueCharacter(char ch);
    char dequeueCharacter();    
};

//Stack Operations
void Solution :: pushCharacter(char ch) {
    this -> stack[this -> stack_len] = ch;
    stack_len++;
    stack_ptr = stack_len - 1;
}

char Solution :: popCharacter() {
    stack_len--;
    return this -> stack[this -> stack_ptr--];
}

//Queue Operations
void Solution :: enqueueCharacter(char ch) {
    this -> queue[this -> queue_len] = ch;
    queue_len++;
}

char Solution :: dequeueCharacter() {
    queue_len--;
    return this -> queue[this -> queue_ptr++];
}


/*
Sample Input

racecar

Sample Output

The word, racecar, is a palindrome.
*/

int main() {
    // read the string s.
    string s;
    getline(cin, s);
    
  	// create the Solution class object p.
    Solution obj;
    
    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }
    
    bool isPalindrome = true;
    
    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;
            
            break;
        }
    }
    
    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }
    
    return 0;
}