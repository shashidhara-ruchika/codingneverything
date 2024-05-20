// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;



class Result {

    /*
     * Complete the 'countMinimumOperations' function below.
     *
     * The function is expected to return a LONG_INTEGER_ARRAY.
     * The function accepts following parameters:
     *  1. INTEGER_ARRAY price
     *  2. INTEGER_ARRAY query
     */

    public static List<Long> countMinimumOperations(List<Integer> price, List<Integer> query) {
    // Write your code here
        // List<Long> result = new ArrayList<>();
        // Map<Integer, Long> calc = new HashMap<>();
        // for (Integer q : query) {
        //     if (calc.containsKey(q)) {
        //         result.add(calc.get(q));
        //         continue;
        //     }
            
        //     Long op = 0L;
        //     for (Integer p : price) {
        //         op += Math.abs( p.longValue() - q.longValue() );
        //     }
        //     result.add(op);
        //     calc.put(q, op);
        // }
        
        // return result;
        
        int n = price.size();
        
        int[] priceArray = price.stream().mapToInt(i -> i).toArray();
        
        List<Long> result = new ArrayList<>();
        
        Arrays.sort(priceArray);
        
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + priceArray[i];
        }
        
        for (int q : query) {
            int i = binarySearch(priceArray, q);
            result.add(1L * q * i - prefix[i] + prefix[n] - prefix[i] - 1L * (n - i) * q);
        }
        
        return result;
        
        
    }
    
    private static int binarySearch(int nums[], int key) {
        int l = 0, h = nums.length;
        while (l < h) {
            int m = l + (h - l) / 2;
            if (key > nums[m]) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }


}

public class minimum-operations-to-make-all-array-elements-equal {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int priceCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> price = IntStream.range(0, priceCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int queryCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> query = IntStream.range(0, queryCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        List<Long> result = Result.countMinimumOperations(price, query);

        bufferedWriter.write(
            result.stream()
                .map(Object::toString)
                .collect(joining("\n"))
            + "\n"
        );

        bufferedReader.close();
        bufferedWriter.close();
    }
}
