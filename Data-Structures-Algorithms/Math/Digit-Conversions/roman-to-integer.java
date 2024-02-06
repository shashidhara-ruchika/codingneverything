
    import java.util.HashMap;
import java.util.Scanner;

public class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> romanToInt = new HashMap<>();
        romanToInt.put('I', 1);
        romanToInt.put('V', 5);
        romanToInt.put('X', 10);
        romanToInt.put('L', 50);
        romanToInt.put('C', 100);
        romanToInt.put('D', 500);
        romanToInt.put('M', 1000);

        int sLen = s.length();
        int intTotal = 0;

        char prev = s.charAt(0);
        int i = 1;

        while (i < sLen) {
            char curr = s.charAt(i);

            if ((prev == 'I' && (curr == 'V' || curr == 'X')) || (prev == 'X' && (curr == 'L' || curr == 'C')) ||
                    (prev == 'C' && (curr == 'D' || curr == 'M'))) {
                intTotal -= romanToInt.get(prev);
            } else {
                intTotal += romanToInt.get(prev);
            }

            prev = curr;
            i++;
        }

        intTotal += romanToInt.get(s.charAt(sLen - 1));

        return intTotal;
    }

    public void solve() {
        Scanner scanner = new Scanner(System.in);
        String romanNumeral = scanner.next();
        System.out.println(romanToInt(romanNumeral));
    }

    public static void main(String[] args) {
        Solution soln = new Solution();
        Scanner scanner = new Scanner(System.in);
        String romanNumeral = scanner.next();
        System.out.println(soln.romanToInt(romanNumeral));
    }
}

