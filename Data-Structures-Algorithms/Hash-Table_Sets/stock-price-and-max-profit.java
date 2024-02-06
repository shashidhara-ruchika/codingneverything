// https://leetcode.com/discuss/interview-question/4102987/IBM-OA-or-SWE

import java.util.*;

public class Solution {

    void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] price = new int[n];
        int[] profit = new int[n];

        for (int i = 0; i < n; i++)
            price[i] = sc.nextInt();

        for (int i = 0; i < n; i++)
            profit[i] = sc.nextInt();

        int maxSum = 0;
        TreeMap<Pair, Integer> leftMax = new TreeMap<>();
        TreeMap<Pair, Integer> rightMax = new TreeMap<>();

        for (int i = n - 1; i >= 1; i--) {
            Map.Entry<Pair, Integer> entry = rightMax.higherEntry(new Pair(price[i], 0));
            if (entry == null) {
                rightMax.put(new Pair(price[i], i), profit[i]);
            } else {
                rightMax.put(new Pair(price[i], i), Math.max(profit[i], entry.getValue()));
            }
        }

        for (int i = 1; i < n - 1; i++) {
            Map.Entry<Pair, Integer> entry = leftMax.higherEntry(new Pair(price[i - 1], 0));
            if (entry != null) {
                entry = leftMax.lowerEntry(new Pair(price[i - 1], 0));
                leftMax.put(new Pair(price[i - 1], i - 1), Math.max(profit[i - 1], entry.getValue()));
            } else {
                leftMax.put(new Pair(price[i - 1], i - 1), profit[i - 1]);
            }

            rightMax.remove(new Pair(price[i], i));

            Map.Entry<Pair, Integer> find1 = leftMax.higherEntry(new Pair(price[i], 0));
            if (find1 != null) {
                find1 = leftMax.lowerEntry(new Pair(price[i], 0));
                Map.Entry<Pair, Integer> find2 = rightMax.higherEntry(new Pair(price[i], 0));
                if (find2 != null) {
                    maxSum = Math.max(maxSum, find1.getValue() + find2.getValue() + profit[i]);
                }
            }
        }

        System.out.println(maxSum);
    }

    class Pair implements Comparable<Pair> {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public int compareTo(Pair other) {
            return Integer.compare(this.first, other.first);
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        solution.solve();
    }
}
