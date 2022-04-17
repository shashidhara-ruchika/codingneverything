/*
https://www.hackerrank.com/challenges/java-arraylist/problem?isFullScreen=true
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
        
        int n = scan.nextInt();
        
        ArrayList<ArrayList<Integer>> xList = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int d = scan.nextInt();
            ArrayList<Integer> yList = new ArrayList<>();
            for (int j = 0; j < d; j++) {
                yList.add(scan.nextInt());
            }
            xList.add(yList);
        }
        
        int q = scan.nextInt();
        
        for (int i = 0; i < q; i++) {
            int row = scan.nextInt(); // x
            int col = scan.nextInt(); // y
            
            try {
                System.out.println(xList.get(row - 1).get(col - 1));
            }
            catch(Exception e) {
                System.out.println("ERROR!");
            }
            
        }
        
        scan.close();
    }
}


/*
Sample Input

5
5 41 77 74 22 44
1 12
4 37 34 36 52
0
3 20 22 33
5
1 3
3 4
3 1
4 3
5 5

Sample Output

74
52
37
ERROR!
ERROR!
*/
