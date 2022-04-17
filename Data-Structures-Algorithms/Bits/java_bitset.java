/*
https://www.hackerrank.com/challenges/java-bitset/problem?isFullScreen=true
*/

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int m = scan.nextInt();
      
        BitSet b1 = new BitSet(n);
        BitSet b2 = new BitSet(n);
        BitSet[] bitset = new BitSet[3];
      
        bitset[1] = b1;
        bitset[2] = b2;
      
        while ( 0 < m-- ) {
          String op = scan.next();
          int x = scan.nextInt();
          int y = scan.nextInt();
          
          switch (op) {
            case "AND":
              bitset[x].and(bitset[y]);
              break;
            case "OR":
              bitset[x].or(bitset[y]);
              break;
            case "XOR":
              bitset[x].xor(bitset[y]);
              break;
            case "FLIP":
              bitset[x].flip(y);
              break;
            case "SET":
              bitset[x].set(y);
          }
          
          System.out.printf("%d %d%n", b1.cardinality(), b2.cardinality());
        }
          
        scan.close();
    }
}

/*
Sample Input

5 4
AND 1 2
SET 1 4
FLIP 2 2
OR 2 1

Sample Output

0 0
1 0
1 1
1 2
*/
