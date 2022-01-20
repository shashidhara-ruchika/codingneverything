
// https://www.hackerrank.com/challenges/java-string-tokens/copy-from/252618678

import java.io.*;
import java.util.*;

public class Solution {
    
    public static String[] returnTokens(String s) {
        String[] tokens = s.trim().split("[ !,?._'@]+");
        /*for(String token : tokens) {
            System.out.println(": " + token);
        }*/
        return tokens;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        scan.close();
        
        if (s.trim().length()==0 || s.trim().length()>400000)
        {
            System.out.println(0);
            return;
        }
        
        String[] tokens = returnTokens(s);
        
        //if (tokens.isEmpty())
          //  System.out.println("0");
        
        System.out.println(tokens.length);
        
        
        for(String token : tokens) {
            System.out.println(token);
        }
        
    }
}



