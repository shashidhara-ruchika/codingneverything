// https://www.hackerrank.com/challenges/java-string-reverse/copy-from/252528933

import java.io.*;
import java.util.*;

public class Solution {
    
    public static boolean isPalindrome(String a) {
        
        java.text.CharacterIterator it_forward = new java.text.StringCharacterIterator(a);
        java.text.CharacterIterator it_backward = new java.text.StringCharacterIterator(a, a.length() - 1);
        
        while(it_forward.getIndex() < it_backward.getIndex()) {
            //System.out.println(it_forward.current() + " " + it_backward.current());
            if (it_forward.current() != it_backward.current()) 
                return false;
            it_forward.next();
            it_backward.previous();
        }
        
        return true;
        
        /*
        char[] a_charArray = a.toCharArray();
        
        int front_index = 0;
        int back_index = a_charArray.length - 1;
        
        while(front_index < back_index) {
            if (a_charArray[front_index++] != a_charArray[back_index--])
                return false;
        }
        
        return true;
        */
        
        /*
        int front_index = 0;
        int back_index = a.length() - 1;
        
        while(front_index < back_index) {
            if (a.charAt(front_index++) != a.charAt(back_index--))
                return false;
        }
        
        return true;
        */
    }

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        boolean string_is_palindrome = isPalindrome(A);
        System.out.println((string_is_palindrome) ? ("Yes") : ("No"));
    }
}




