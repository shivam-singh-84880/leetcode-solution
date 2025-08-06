class Solution {
public:
    int count(int row, int col, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(row < 0 || col < 0) return 0;
        if(obstacleGrid[row][col] == 1) return 0;
        if(row == 0 && col == 0) return 1;

        if(dp[row][col] != -1) return dp[row][col];

        int up = count(row-1,col,obstacleGrid,dp);
        int down = count(row,col-1,obstacleGrid,dp);

        return dp[row][col] = up+down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j] = 1;
                    continue;
                }
                
                int up = 0;
                int down = 0;
                if(i>=1) up = dp[i-1][j];
                if(j>=1) down = dp[i][j-1];
                dp[i][j] = up+down;
            }
        }
        return dp[n-1][m-1];
        //return count(n-1,m-1,obstacleGrid,dp);
    }
};