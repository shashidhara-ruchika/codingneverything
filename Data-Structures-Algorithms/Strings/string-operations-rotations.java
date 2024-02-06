// https://gist.github.com/imeanup/13bf994b41612277ed61054f24599b4a

public class Solution {

    public static String solve(String s, String[] operations) {
        char[] chars = s.toCharArray();

        for (String op : operations) {
            String[] parts = op.split(" ");
            int start = Integer.parseInt(parts[0]);
            int end = Integer.parseInt(parts[1]);
            char dire = parts[2].charAt(0);

            for (int i = start; i <= end; i++) {
                if (dire == 'L') {
                    chars[i] = (char) ((chars[i] - 'a' + 24) % 26 + 'a');
                } else {
                    chars[i] = (char) ((chars[i] - 'a' + 1) % 26 + 'a');
                }
            }
        }

        return new String(chars);
    }

    public static void main(String[] args) {
        String result = solve("abc", new String[]{"0 0 L", "2 2 L", "0 2 R"});
        System.out.println(result);
    }
}
