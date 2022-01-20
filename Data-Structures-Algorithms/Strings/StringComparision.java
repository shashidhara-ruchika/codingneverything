// https://www.hackerrank.com/challenges/java-string-compare/copy-from/252519745

import java.util.Scanner;

public class Solution {

    public static String getSmallestAndLargest(String s, int k) {
        String smallest = s.substring(0, k);
        String largest = smallest;
        
        // Complete the function
        // 'smallest' must be the lexicographically smallest substring of length 'k'
        // 'largest' must be the lexicographically largest substring of length 'k'
        
        for(int i = 1; i < s.length() - k + 1; ++i) {
            String ss = s.substring(i, i + k);
            if (ss.compareTo(smallest) < 0)
                smallest = ss;
            if (ss.compareTo(largest) > 0)
                largest = ss;
        }
        
        return smallest + "\n" + largest;
    }

//import java.lang.String;


    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        int k = scan.nextInt();
        scan.close();
      
        System.out.println(getSmallestAndLargest(s, k));
    }
}
