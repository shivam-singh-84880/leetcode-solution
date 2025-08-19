class Solution {
public:
    int find(int ind, int t, vector<int>& coins,vector<vector<int>>& dp){
        if(ind == 0){
            return (t % coins[0] == 0);
        }
        if(dp[ind][t] != -1)return dp[ind][t];
        int ntk = find(ind-1,t,coins,dp);
        int tk = 0;
        if(t >= coins[ind]){
            tk = find(ind,t-coins[ind],coins,dp);
        }
        return dp[ind][t] = tk + ntk;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return find(n-1,amount,coins,dp);
    }
};