class Solution {
public:
    int find(int ind, int bs, int n, vector<int>& prices, int& fee,vector<vector<int>>& dp){
        if(ind == n)return 0;
        if(dp[ind][bs] != -1)return dp[ind][bs];
        if(bs){
            return dp[ind][bs] = max(-prices[ind] + find(ind+1,0,n,prices,fee,dp), find(ind+1,1,n,prices,fee,dp));
        }
        else{
            return dp[ind][bs] = max(prices[ind] - fee + find(ind+1,1,n,prices,fee,dp), find(ind+1,0,n,prices,fee,dp));
        }
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return find(0,1,n,prices,fee,dp);
    }
};