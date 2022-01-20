// https://www.hackerrank.com/challenges/java-anagrams/copy-from/252522510

import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        // Complete the function
        
        if (a.length() != b.length())
            return false;
        
        char[] a_charArray = a.toUpperCase().toCharArray();
        char[] b_charArray = b.toUpperCase().toCharArray();
        
        java.util.HashMap<Character, Integer> freq = new java.util.HashMap<>();
        
        for(char c : a_charArray) {
            if (freq.containsKey(c)) {
                int current_value = freq.get(c);
                freq.put(c, current_value + 1);
            }
            else {
                freq.put(c, 1);
            }
        }
        
        for(char c : b_charArray) {
            if (freq.containsKey(c)) {
                int current_value = freq.get(c);
                freq.put(c, current_value - 1);
            }
            else {
                freq.put(c, -1);
            }
        }
        
        for(Integer f : freq.values()) {
            if (f != 0)
                return false;
        }

        return true;
    }

  public static void main(String[] args) {
    
        Scanner scan = new Scanner(System.in);
        String a = scan.next();
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println( (ret) ? "Anagrams" : "Not Anagrams" );
    }
}

