
// https://leetcode.com/discuss/interview-question/1874750/minimize-array-cost

import java.util.List;

public class Solution {

    public static int minCost(List<Integer> arr) {
        int maxDiff = 0;
        int index = -1;

        for (int i = 0; i < arr.size() - 1; i++) {
            if (Math.abs(arr.get(i) - arr.get(i + 1)) > maxDiff) {
                maxDiff = Math.abs(arr.get(i) - arr.get(i + 1));
                index = i;
            }
        }

        int median = (arr.get(index) - arr.get(index + 1)) / 2;

        int initialCost = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            initialCost += Math.pow(arr.get(i) - arr.get(i + 1), 2);
        }

        initialCost = initialCost + (int) Math.pow(arr.get(index) - median, 2) + (int) Math.pow(median - arr.get(index + 1), 2)
                - (int) Math.pow(arr.get(index) - arr.get(index + 1), 2);

        return initialCost;
    }

    public static void main(String[] args) {
        // Example usage:
        List<Integer> arr = List.of(1, 4, 2, 8, 5, 7);
        int result = minCost(arr);
        System.out.println(result);
    }
}
