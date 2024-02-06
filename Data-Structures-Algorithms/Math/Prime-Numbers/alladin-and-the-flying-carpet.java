import java.util.ArrayList;
import java.util.BitSet;
import java.util.Scanner;

public class Main {
    static ArrayList<Integer> primes;

    static void sieve() {
        final int SZ = 1000003;
        BitSet status = new BitSet(SZ);
        int rt = 1000;

        for (int i = 3; i < rt; i += 2)
            if (!status.get(i))
                for (int j = i * i; j < SZ; j += (i << 1))
                    status.set(j, true);

        primes = new ArrayList<>();
        primes.add(2);

        for (int i = 3; i < SZ; i += 2)
            if (!status.get(i))
                primes.add(i);
    }

    static int numberOfDivisors(long n) {
        int sz = primes.size(), cnt = 1;

        for (int i = 0; i < sz && primes.get(i) * primes.get(i) <= n; ++i) {
            if (n % primes.get(i) == 0) {
                int pw = 0;
                while (n % primes.get(i) == 0) {
                    ++pw;
                    n /= primes.get(i);
                }
                cnt *= pw + 1;
            }
        }

        if (n != 1) cnt <<= 1;

        return cnt;
    }

    public static void main(String[] args) {
        sieve();

        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();

        for (int tc = 1; tc <= t; ++tc) {
            long n = scanner.nextLong();
            long d = scanner.nextLong();

            int rt = (int) Math.sqrt(n);
            int ans;

            if (d > rt || d * d == n) {
                ans = 0;
            } else {
                ans = numberOfDivisors(n) / 2;

                for (int i = 1; i < d; ++i)
                    if (n % i == 0) --ans;
            }

            System.out.println("Case " + tc + ": " + ans);
        }
    }
}
