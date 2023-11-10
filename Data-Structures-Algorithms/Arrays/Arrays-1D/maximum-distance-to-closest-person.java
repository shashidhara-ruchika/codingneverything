/*
You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to the closest person.
*/

class Solution {
    public int maxDistToClosest(int[] seats) {
        int maxDist = 0;
        int pos = -1;
        for (int i = 0; i < seats.length; i++) {
            // empty seat
            if (seats[i] == 0) {
                
                // go left
                int l = i - 1;
                while (l >= 0) {
                    // full seat
                    if (seats[l] == 1) {
                        break;
                    }
                    l--;
                }
                
                // go right
                int r = i + 1;
                while (r < seats.length) {
                    if (seats[r] == 1) {
                        break;
                    }
                    r++;
                    
                }
                
                int dist = 0;
                if (i - 1 < 0 ) {
                    dist = r - i;
                } else if (r >= seats.length) {
                    dist = i - l;
                } else {
                    dist = Math.min(i - l, r - i);
                    
                }
                
                if (dist > maxDist) {
                        maxDist = dist;
                        pos = i;
                    }

            
            }
            
        }
        return maxDist;
    }
}