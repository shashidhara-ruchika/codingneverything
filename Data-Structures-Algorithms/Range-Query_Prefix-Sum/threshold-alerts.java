/*

https://leetcode.com/discuss/interview-question/444027/linkedin-oa-2019-hashed-ports-threshold-alerts


 * Threshold Alerts
A compliance system monitors incoming and outbound calls. It sends an alert whenever the average calls exceed a threshold over a trailing number of minutes, preceding Minutes = 5, if the trailing minutes to consider, at time T, average the call volumes for times T-(5-1), T-(5-2) ...Τ.
Example
n = 8
numCalls = [2, 2, 2, 2, 5, 5, 5, 8] alert Threshold = 4 preceding Minutes = 3
No alerts will be sent until at least T = 3 because there are not enough values to consider. When T = 3, the average calls = (2 + 2+2)/3 = 2. Additionally, average calls from T = 3 to T = 8 are 2, 2, 3, 4, 5, and 6. A total of two alerts are sent during the last two periods. Given the data as described, determine the number of alerts sent at the end of the timeframe.
Function Description
Complete the numberOfAlerts function in the editor below. It should return an integer that represents the number of alerts sent over the timeframe.
numberOfAlerts has the following parameter(s):
preceding Minutes: an integer that represents the trailing number of minutes to consider.
alert Threshold: an integer that represents the maximum number of calls allowed without triggering an alert.
numCalls[numCalls[0]..num Calls[n-1]]: an array of integers where num Calls[i] represents the number of calls made during each minute with and index of i.
Constraints
1 ≤ preceding Minutes ≤ n
1 ≤ alert Threshold ≤ 105
1 ≤ n ≤ 105
0 ≤ numCalls[i] ≤ 105
 */
public import java.io.*;
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
     * Complete the 'numberOfAlerts' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER precedingMinutes
     *  2. INTEGER alertThreshold
     *  3. INTEGER_ARRAY numCalls
     */

    public static int numberOfAlerts(int precedingMinutes, int alertThreshold, List<Integer> numCalls) {
    // Write your code here
    
    System.out.println("preceeding min:  " + precedingMinutes);
    System.out.println("alert threshold: " + alertThreshold);
    System.out.println("size of calls:   " + numCalls.size());
    
    double alertFactor = (double) precedingMinutes * (double) alertThreshold;
    
    Double currentSum = 0.0;
    for(int i = 0; i < precedingMinutes; i++) {
        currentSum += (double) numCalls.get(i);
    }
    
    int alertCount = 0;
    if (currentSum > alertFactor) {
        alertCount++;
    }
    
    for (int i = precedingMinutes; i < numCalls.size(); i++) {
        
        currentSum += (double)numCalls.get(i);
        if (alertThreshold > 1) {
            currentSum -= (double)numCalls.get(i - precedingMinutes);
        }
        if (currentSum > alertFactor) {
            alertCount++;
        }        
    }
    
    
    return alertCount;

    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int precedingMinutes = Integer.parseInt(bufferedReader.readLine().trim());

        int alertThreshold = Integer.parseInt(bufferedReader.readLine().trim());

        int numCallsCount = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> numCalls = IntStream.range(0, numCallsCount).mapToObj(i -> {
            try {
                return bufferedReader.readLine().replaceAll("\\s+$", "");
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .map(String::trim)
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.numberOfAlerts(precedingMinutes, alertThreshold, numCalls);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
 alertThreshold {
    
}
