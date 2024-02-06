

// https://leetcode.com/discuss/interview-question/4103014/IBM-OA-Front-End


public class Solution {
    public static long minMoves(int[] quantity, int n) {
        int[] prefix = new int[quantity.length];
        int[] suffix = new int[quantity.length];

        prefix[0] = quantity[0];
        for (int i = 1; i < quantity.length; i++) {
            prefix[i] = prefix[i - 1] + quantity[i];
        }
        suffix[quantity.length - 1] = quantity[quantity.length - 1];
        for (int i = quantity.length - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + quantity[i];
        }

        long minValue = Integer.MAX_VALUE;

        for (int i = 0; i < prefix.length - 1; i++) {
            minValue = Math.min(minValue, Math.abs(prefix[i] - suffix[i + 1]));
        }
        return minValue;
    }

    public static void main(String[] args) {
        int[] quantity = {3, 3, 6, 3, 9};
        int n = 5;
        long result = minMoves(quantity, n);
        System.out.println(result);
    }
}
