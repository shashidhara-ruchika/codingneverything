

public class Solution {

    public static int countValidWords(String stt) {
        String[] words = stt.split("\\s+");
        char[] vowels = {'a', 'e', 'i', 'o', 'u'};
        boolean hasVowels = false;
        boolean hasConsonants = false;
        int count = 0;

        for (String word : words) {
            if (word.matches("\\w+") && word.length() >= 3) {
                for (char cha : word.toCharArray()) {
                    if (new String(vowels).contains(String.valueOf(cha))) {
                        hasVowels = true;
                    }
                    if (Character.isLetter(cha) && !new String(vowels).contains(String.valueOf(cha))) {
                        hasConsonants = true;
                    }
                }
                if (hasConsonants && hasVowels) {
                    count++;
                }
            }
            hasVowels = false;
            hasConsonants = false;
        }

        return count;
    }

    public static void main(String[] args) {
        int res = countValidWords("This is a valid stateme$nt test abcd2 aaaa2 aab3");
        System.out.println(res);
    }
}
