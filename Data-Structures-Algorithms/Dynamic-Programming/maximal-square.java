// https://leetcode.com/problems/maximal-square/description/

class Solution {
    public int maximalSquare(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }

        int row = matrix.length;
        int cols = matrix[0].length;
        int max_indp = 0;

        int[][] dp = new int[row][cols];

        for (int j = 0; j < cols; j++) {
            dp[row - 1][j] = matrix[row - 1][j] - '0';
            max_indp = Math.max(max_indp, dp[row - 1][j]);
        }

        for (int i = 0; i < row; i++) {
            dp[i][cols - 1] = matrix[i][cols - 1] - '0';
            max_indp = Math.max(max_indp, dp[i][cols - 1]);
        }

        for (int i = row - 2; i >= 0; i--) {
            for (int j = cols - 2; j >= 0; j--) {
                int step1 = dp[i][j + 1];
                int step2 = dp[i + 1][j];
                int step3 = dp[i + 1][j + 1];

                int ans = Math.min(step1, Math.min(step2, step3));

                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    ans++;
                    max_indp = Math.max(max_indp, ans);
                    dp[i][j] = ans;
                }
            }
        }

        return max_indp * max_indp;
    }

    static class Solution {
        char[][] matrix;
        int m;
        int n;
        int max;
        public int maximalSquare(char[][] matrix) {
            this.matrix=matrix;
            m=matrix.length;
            n=matrix[0].length;
            Integer[][] dp=new Integer[m][n];
            // topDown(m-1,n-1, dp);
            bottomUp();
            return max;
        }
        
        int topDown(int row,int col, Integer[][] dp){
            //return 0 if array out of bounds
            if(row<0 || row>=m|| col<0 || col>=n)
                return 0;
            if(dp[row][col]!=null)
                return dp[row][col];
            /*fill the max area at the bottom right corner of a sqaure.
            It depdendes on top, diagoanal and left cells. Recursive they depend on their prev cells
            start with 1x1, 2x2, 3x3....*/
            int top=topDown(row-1,col,dp);
            int dia=topDown(row-1,col-1,dp);
            int left=topDown(row,col-1,dp);
            if(matrix[row][col]!='0'){
                int min=(int)Math.min(top,Math.min(dia,left));
                /*formula: find min of top,left and dia; lets say Min(16,9,4)=4, if current cell value is 1
                 it means it will form 3x3 area. so square(sqrt(4)+1)
                */
                int result=(int)Math.pow(Math.sqrt(min)+(matrix[row][col]-'0'),2);
                max=(int)Math.max(result,max);
                dp[row][col]=result;
                return result;
            }
            dp[row][col]=0;
            return 0;
        }
        
        void bottomUp(){
            int[][] dp=new int[m][n];
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 || j==0){
                        dp[i][j]=matrix[i][j]-'0';
                    } else if(matrix[i][j]!='0'){
                        int min=(int)Math.min(dp[i-1][j],Math.min(dp[i-1][j-1],dp[i][j-1]));
                        dp[i][j]=(int)Math.pow(Math.sqrt(min)+(matrix[i][j]-'0'),2);
                    }
                    max=Math.max(max,dp[i][j]);
                }
            }
        }
    }
    
}
