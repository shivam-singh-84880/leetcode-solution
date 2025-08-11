class Solution {
public:
    int find(int row, int col, int n, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(dp[row][col] != -1)return dp[row][col];
        if(row == n-1)return triangle[row][col];
        int s1 = triangle[row][col] + find(row+1,col,n,triangle,dp);
        int s2 = triangle[row][col] + find(row+1,col+1,n,triangle,dp);

        return dp[row][col] = min(s1,s2);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n; i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int s1 = triangle[i][j] + dp[i+1][j];
                int s2 = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(s1,s2);
            }
        }
        return dp[0][0];
        //return find(0,0,n,triangle,dp);
    }
};