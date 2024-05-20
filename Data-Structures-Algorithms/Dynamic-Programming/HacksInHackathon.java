/*
hackathon organized by HackerRank which has 2 separate tracks, healthcare and e- commerce. 
For track 1, the required team size is teamSize_1, while for track 2, the required team size is teamSize_2. 
The total number of participants is p.

Find the minimum number of teams into which the participants can be divided 
such that each participant belongs to exactly one team (either of track 1 or track 2), 
and each team has a size equal to either teamSize_1 or teamSize_2. 
If no such division is possible, return -1. 

 */
public class HacksInHackathon {

    public static int minTeams(int p, int teamSize_1, int teamSize_2) {
        // Create dp array with 'inf' initialized
        int[] dp = new int[p + 1];
        final int INF = Integer.MAX_VALUE;
        
        // Initialize dp array
        for (int i = 1; i <= p; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        
        // DP transition
        for (int i = 1; i <= p; i++) {
            if (i >= teamSize_1 && dp[i - teamSize_1] != INF) {
                dp[i] = Math.min(dp[i], dp[i - teamSize_1] + 1);
            }
            if (i >= teamSize_2 && dp[i - teamSize_2] != INF) {
                dp[i] = Math.min(dp[i], dp[i - teamSize_2] + 1);
            }
        }
        
        return dp[p] == INF ? -1 : dp[p];
    }

    public static void main(String[] args) {
        int p = 12;
        int teamSize_1 = 3;
        int teamSize_2 = 4;
        System.out.println(minTeams(p, teamSize_1, teamSize_2));  // Output should be the minimum number of teams or -1 if not possible
    }
}

