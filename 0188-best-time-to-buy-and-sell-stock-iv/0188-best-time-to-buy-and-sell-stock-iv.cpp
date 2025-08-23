class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // B S B S
        vector<int> curr(2*k+1,0);

        for(int ind=n-1; ind>=0; ind--){
            for(int trx=0; trx<2*k; trx++){
                if(trx % 2 == 0){
                    curr[trx] = max(-prices[ind] + curr[trx+1], curr[trx]);
                }
                else{
                    curr[trx] = max(prices[ind] + curr[trx+1], curr[trx]);
                }    
            }
        }
        return curr[0];

    }
};