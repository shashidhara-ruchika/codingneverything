// https://leetcode.com/problems/decode-ways/description/

public class DecodeWays {
    public int numDecodings(String s) {
        int n = s.length();
        if (n == 0) return 0;
        
        // Initialize dp array
        int[] dp = new int[n + 1];
        dp[0] = 1; // Base case: empty string
        dp[1] = (s.charAt(0) != '0') ? 1 : 0; // Only one way to decode single character
        
        for (int i = 2; i <= n; i++) {
            // Check single digit
            int oneDigit = Integer.parseInt(s.substring(i - 1, i));
            if (oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i - 1];
            }
            
            // Check two digits
            int twoDigits = Integer.parseInt(s.substring(i - 2, i));
            if (twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
    
    public static void main(String[] args) {
        DecodeWays decoder = new DecodeWays();
        String input = "2112";
        System.out.println("Number of possible decodings: " + decoder.numDecodings(input)); // Output: 5
    }
}
