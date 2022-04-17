/*
https://www.hackerrank.com/challenges/java-list/problem?isFullScreen=true
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        
        List<Integer> linkedList = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            linkedList.add(scan.nextInt());
        }
        
        int Q = scan.nextInt();
        for (int i = 0; i < Q; i++) {
            String action = scan.next();
            int index = scan.nextInt();
            if (action.equals("Insert")) {
                int value = scan.nextInt();
                linkedList.add(index, value);
            } 
            else {
                linkedList.remove(index);
            }
        }
        scan.close();
        
        for(Integer value : linkedList) {
            System.out.print(value + " ");
        }
        
    }
}

/*
Sample Input

5
12 0 1 78 12
2
Insert
5 23
Delete
0
Sample Output

0 1 78 12 23
*/
