

public class Solution {

    public static int calculateMinCost(String pass, Pair p1, Pair p2) {
        int minc = Math.min(p1.first, p1.second);

        for (int i = 0; i < pass.length(); i++) {
            if (i % 2 == 0) {
                int change = Math.min(p2.first, p2.second) + Math.min(p1.first, p1.second);
                minc = Math.min(minc, change);
            }

            if (pass.charAt(i) == '0') {
                p1.first--;
                p2.first++;
            } else {
                p1.second--;
                p2.second++;
            }
        }

        return minc;
    }

    public static void main(String[] args) {
        // Example usage:
        String pass = "010101";
        Pair p1 = new Pair(2, 3);
        Pair p2 = new Pair(1, 4);
        int result = calculateMinCost(pass, p1, p2);
        System.out.println(result);
    }

    static class Pair {
        int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}


public class Solution 2 {
public static void main(String[] args) {
    String password = "010101";  // Input string
    int result = getMinFlips(password);
    System.out.println(result);  // Output: 3
}

public static int getMinFlips(String password) {
    int flipCount = 0;

    for (int i = 0; i < password.length() - 1; i += 2) {
        // Check each pair of characters
        char firstChar = password.charAt(i);
        char secondChar = password.charAt(i + 1);

        // If the characters are different, increment flipCount
        if (firstChar != secondChar) {
            flipCount++;
        }
    }

    return flipCount;
}
}