class Solution {
public:
    int find(int row, int col, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(col < 0 || col >= n)return 1e9;
        if(row == 0) return matrix[row][col];
        if(dp[row][col] != -1)return dp[row][col];
        int s1 = matrix[row][col] + find(row-1,col-1,n,matrix,dp);
        int s2 = matrix[row][col] + find(row-1,col,n,matrix,dp);
        int s3 = matrix[row][col] + find(row-1,col+1,n,matrix,dp);

        return dp[row][col] = min(s1,min(s2,s3));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n,vector<int> (n,0));

        for(int i=0; i<n; i++){
            dp[0][i] = matrix[0][i];
        }

        for(int row=1; row<n; row++){
            for(int col=0; col<n; col++){

                int s1 = matrix[row][col];
                if(col > 0){
                    s1 += dp[row-1][col-1];
                } 
                else{
                    s1 = 1e9;
                }

                int s2 = matrix[row][col] + dp[row-1][col];

                int s3 = matrix[row][col];
                if(col+1 < n){
                    s3 += dp[row-1][col+1];
                }
                else{
                    s3 = 1e9;
                }
                dp[row][col] = min(s1,min(s2,s3));
            }
        }

        for(int i=0; i<n; i++){
            ans = min(ans,dp[n-1][i]);
        }
        return ans;   
    }
};