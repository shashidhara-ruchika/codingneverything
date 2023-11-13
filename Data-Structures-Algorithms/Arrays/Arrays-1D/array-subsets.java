/*
Given an integer array, divide the array into 2 subsets A & B while:
A intersection B = null
A union B = original array
Number of elements in A is minimal
Sum of A's elements > Sum of B's elements

Return subsetA in increasing order where the sum of A's elements is greater than sum of B's elements. 
If more than one subset exists, return the one with the maximal sum.
*/

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
     * Complete the 'subsetA' function below.
     *
     * The function is expected to return an INTEGER_ARRAY.
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static List<Integer> subsetA(List<Integer> arr) {
        int n = arr.size();
        arr.sort(null);
        
        if (arr.size() == 1) {
            return arr;
        }
        
        List<Integer> sol = new ArrayList<>();
        List<Double> inc = new ArrayList<>();
        List<Double> dec = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            inc.add(new Double(0));
            dec.add(new Double(0));
        }
        
        inc.set(0, new Double(arr.get(0)));
        dec.set(n - 1, new Double(arr.get(n - 1)));
        
        for (int i = 1; i < n; i++) {
            inc.set(i, arr.get(i) + inc.get(i - 1));
        }
        
        for (int i = n - 2; i >= 0; i--) {
            dec.set(i, arr.get(i) + dec.get(i + 1));
        }
        
        int p = n - 1;
        while (p >= 0 && dec.get(p) <= inc.get(p - 1)) {
            p--;
        }
        
        
        for (int i = p; i < n; i++) {
            sol.add(arr.get(i));
        }     
        
        System.out.println(n);
        
        return sol;

    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int arrCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = IntStream.range(0, arrCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        List<Integer> result = Result.subsetA(arr);

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
