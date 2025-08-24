class Solution {
public:
    int find(int ind, int bs, vector<int>& prices, int n){
        if(ind >= n)return 0;
        if(bs){
            return max(-prices[ind] + find(ind+1,0,prices,n), find(ind+1,1,prices,n));
        }
        else{
            return max(prices[ind] + find(ind+2,1,prices,n), find(ind+1,0,prices,n));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       // return find(0,1,prices,n);
        vector<vector<int>> dp(n+2, vector<int>(2,0));
        //vector<int> curr(2*n+1,0);

        for(int ind=n-1; ind>=0; ind--){
            for(int bs=0; bs<=1; bs++){
                if(bs){
                    dp[ind][bs] = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
                }
                else{
                    dp[ind][bs] = max(prices[ind] + dp[ind+2][1], dp[ind+1][0]);
                }    
            }
        }
        return dp[0][1];
    }
};