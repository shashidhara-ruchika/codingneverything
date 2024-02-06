import java.util.HashSet;
import java.util.Set;

public class Solution {

    public static Set<Integer> sieve(int num) {
        boolean[] prime = new boolean[num + 1];
        for (int i = 0; i <= num; i++) {
            prime[i] = true;
        }
        prime[0] = prime[1] = false;

        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (prime[i]) {
                for (int j = i * i; j <= num; j += i) {
                    prime[j] = false;
                }
            }
        }

        Set<Integer> primes = new HashSet<>();
        for (int i = 0; i < prime.length; i++) {
            if (prime[i]) {
                primes.add(i);
            }
        }

        return primes;
    }

    public static int solve(int[][] matrix) {
        int n = matrix.length;
        Set<Integer> diag = new HashSet<>();

        // principal diag
        for (int r = 0, c = 0; c < n; c++, r++) {
            diag.add(matrix[r][c]);
        }

        // secondary diag
        for (int r = n - 1, c = 0; c < n; c++, r--) {
            diag.add(matrix[r][c]);
        }

        Set<Integer> primes = sieve(diag.stream().mapToInt(Integer::intValue).max().orElse(0));
        return diag.stream().filter(primes::contains).mapToInt(Integer::intValue).max().orElse(0);
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 2, 3, 4},
                {4, 3, 2, 1},
                {7, 8, 9, 6},
                {13, 5, 4, 3}
        };

        int result = solve(matrix);
        System.out.println(result);
    }
}
