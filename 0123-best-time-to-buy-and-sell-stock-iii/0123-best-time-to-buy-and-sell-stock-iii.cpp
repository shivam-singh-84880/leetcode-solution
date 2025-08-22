class Solution {
public:
    int find(int ind, int bs, int trx, vector<int>& prices, int n, vector<vector<vector<int>>>& dp){
        if(ind == n)return 0;
        if(trx == 0)return 0;
        if(dp[ind][trx][bs] != -1)return dp[ind][trx][bs];
        if(bs){
            return dp[ind][trx][bs] = max(-prices[ind] + find(ind+1,0,trx,prices,n,dp), find(ind+1,1,trx,prices,n,dp));
        }
        else{
            return dp[ind][trx][bs] = max(prices[ind] + find(ind+1,1,trx-1,prices,n,dp), find(ind+1,0,trx,prices,n,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,-1)));
        return find(0,1,2,prices,n,dp);
    }
};