import java.util.*;

// https://www.hackerrank.com/challenges/java-1d-array/problem?isFullScreen=true

public class StepGame {
    private static boolean isSolvable(int leap, int[] game, int i,
        boolean[] solvable, boolean[] visited) {
        /*if (i < 0 || game[i] == 1)
            return false;
        if (i >= game.length)
            return true;
        game[i] = 1;
        return isSolvable(leap, game, i - 1) ||
                isSolvable(leap, game, i + 1) ||
                isSolvable(leap, game, i + leap);    */
        //System.out.println(i);
        
        if (i < 0)
            return false;
            
        if (i >= game.length)
                return true;
            
        //System.out.printf("%d %s %s%n", game[i], solvable[i], visited[i]);
            
        if (visited[i])
            return solvable[i];
            
        else {
            
            visited[i] = true;
            if (game[i] == 1) {
                return solvable[i];
            }
            return isSolvable(leap, game, i - 1, solvable, visited) ||
                isSolvable(leap, game, i + 1, solvable, visited) ||
                isSolvable(leap, game, i + leap, solvable, visited);
        }
            
    }
    
    public static boolean canWin(int leap, int[] game) {
        // Return true if you can win the game; otherwise, return false.
        boolean[] solvable = new boolean[game.length];
        boolean[] visited = new boolean[game.length];
        return isSolvable(leap, game, 0, solvable, visited);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }
            //System.out.println("iteration: " + q);
            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}

