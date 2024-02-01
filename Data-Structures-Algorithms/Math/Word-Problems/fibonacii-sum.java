// https://www.hackerrank.com/challenges/ctci-fibonacci-numbers/problem?isFullScreen=true&h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=recursion-backtracking

import java.util.*;

public class Solution {

    public static int fibonacci_rec(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    
    public static int fibonacci(int n) {
        int n2 = 0, n1 = 1;
        int sum = 0;
        
        for (int i = 2; i <= n; i++) {
            sum = n1 + n2;
            n2 = n1;
            n1 = sum;
        }
        
        return sum;
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.close();
        System.out.println(fibonacci(n));
    }
}