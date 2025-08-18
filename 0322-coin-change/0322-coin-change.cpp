class Solution {
public:
    int find(int ind, vector<int>& coins, int t,vector<vector<int>>& dp){
        if(ind == 0){
            if(t % coins[0] == 0){
                return t/coins[0];
            }
            else return 1e9;
        }
        if(dp[ind][t] != -1)return dp[ind][t];
        int ntk = find(ind-1,coins,t,dp);
        int tk = 1e9;
        if(t >= coins[ind]){
            tk = 1 + find(ind,coins,t-coins[ind],dp);
        }
        return dp[ind][t] = min(tk,ntk);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1,0);
        vector<int> curr(amount+1,0);

        for(int i=0; i<=amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i/coins[0];
            }
            else prev[i] = 1e9;
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<=amount; j++){
                int ntk = prev[j];
                int tk = 1e9;
                if(j >= coins[i]){
                    tk = 1 + curr[j-coins[i]];
                }
                curr[j] = min(tk,ntk);
            }
            prev = curr;
        }
        int ans = prev[amount];

        // int ans = find(n-1,coins,amount,dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};