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
     * Complete the 'minimumSwaps' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts STRING brackets as parameter.
     */
     
    public static boolean isBalanced(String brackets) {
        int i = -1;
        char[] stack = new char[brackets.length()];
        for (char ch : brackets.toCharArray()) {
            if (ch == '(') {
                stack[++i] = ch;
                
            } else {
                if (i >= 0 && (stack[i] == '(' && ch == ')')) {
                    i--;
                } else {
                    return false;
                }
            }
        }
        return i == -1;
    }

    public static int minimumSwaps(String brackets) {
        if (brackets.length() % 2 != 0) {
            return -1;
        }
        
        if (isBalanced(brackets)) {
            return 0;
        }
        
        int stackSize = 0;
        
        for (char ch : brackets.toCharArray()) {
            if (ch == '(') {
                stackSize++;
                
            } else {
                if (stackSize > 0) {
                    stackSize--;
                }
            }
        }
        
        if (stackSize <= 0) {
            return -1;
        }
        
        return (stackSize + 1 ) / 2;
    }

}
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String brackets = bufferedReader.readLine();

        int result = Result.minimumSwaps(brackets);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
