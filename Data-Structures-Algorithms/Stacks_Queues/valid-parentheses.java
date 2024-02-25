// https://leetcode.com/problems/valid-parentheses/

class Solution {

    boolean isBalanced(String s) {
        // Write your code here
        
        Stack<Character> stk = new Stack<>();
        
        for (char c : s.toCharArray()) {
          if (c == '{' || c == '[' || c == '(') {
            stk.push(c);
          } else {
            if (!stk.isEmpty()) {
              char sc = stk.peek();
              if ((c == '}' && sc == '{') || (c == ']' && sc == '[') || (c == ')' && sc == '(')) {
                stk.pop();
              } else {
                return false;
              }
            } else {
              return false;
            }
          }
          
        }
        
        return stk.isEmpty();
        
      }

      
    public boolean isValid(String s) {

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (c == ')') {
                if (!stack.isEmpty() && stack.peek() == '(') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (!stack.isEmpty() && stack.peek() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (!stack.isEmpty() && stack.peek() == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.isEmpty();
        
    }
}