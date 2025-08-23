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
        // B S B S
        vector<int> next(5,0);
        vector<int> curr(5,0);

        for(int ind=n-1; ind>=0; ind--){
            for(int trx=3; trx>=0; trx--){
                if(trx % 2 == 0){
                    curr[trx] = max(-prices[ind] + next[trx+1], next[trx]);
                }
                else{
                    curr[trx] = max(prices[ind] + next[trx+1], next[trx]);
                }    
            }
            next = curr;
        }
        return next[0];




        // vector<vector<int>> next(3,vector<int>(2,0));
        // vector<vector<int>> curr(3,vector<int>(2,0));

        // for(int ind=n-1; ind>=0; ind--){
        //     for(int trx=1; trx<=2; trx++){
        //         for(int bs=0; bs<=1; bs++){
        //             if(bs){
        //                 curr[trx][bs] = max(-prices[ind] + next[trx][0], next[trx][1]);
        //             }
        //             else{
        //                 curr[trx][bs] = max(prices[ind] + next[trx-1][1], next[trx][0]);
        //             }
        //         }
        //     }
        //     next = curr;
        // }
        // return next[2][1];
        //return find(0,1,2,prices,n,dp);
    }
};