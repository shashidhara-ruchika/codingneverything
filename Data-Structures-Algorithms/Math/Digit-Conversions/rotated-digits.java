/*
An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. For example:

0, 1, and 8 rotate to themselves,
2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
6 and 9 rotate to each other, and
the rest of the numbers do not rotate to any other number and become invalid.
Given an integer n, return the number of good integers in the range [1, n].
*/

class Solution {
    public int rotatedDigits(int n) {
        int count = 0;
        for(int j = 1; j <= n; j++) {
            Integer k = j;
            String num = k.toString();
            Set<Character> distinct = new HashSet<>();
            for (int i = 0; i < num.length(); i++) {
                distinct.add(num.charAt(i));
            }
            if (!containsInvalid(distinct) && containsRotate(distinct)) {
                count++;
            }
        }
        return count;        
    }
    //0 1 2 3 4 5 6 7 8 9 10
    
    public boolean containsInvalid(Set<Character> s) {
        return s.contains('3') || s.contains('4') || s.contains('7');
    } 
    
    public boolean containsRotate(Set<Character> s) {
        return s.contains('2') || s.contains('6') || s.contains('5') || s.contains('9');
    } 
    
}