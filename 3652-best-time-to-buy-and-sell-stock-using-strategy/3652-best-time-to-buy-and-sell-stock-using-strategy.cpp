class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int k1 = k/2;
        vector<long long> prefix(n);
        prefix[0] = 1ll*strategy[0]*prices[0];
        for(int i=1; i<n; i++){
            prefix[i] += prefix[i-1] + 1ll*strategy[i]*prices[i];
        }
        long long change = accumulate(prices.begin()+k1,prices.begin()+k,0ll);
        long long ans = max(prefix[n-1], change + prefix[n-1] - prefix[k-1]);

        for(int i=0; i+k<n; i++){
            change += prices[i+k] - prices[i+k1];
            ans = max(ans, change + prefix[n-1] - prefix[i+k] + prefix[i]);
        }
        return ans;
    }
};