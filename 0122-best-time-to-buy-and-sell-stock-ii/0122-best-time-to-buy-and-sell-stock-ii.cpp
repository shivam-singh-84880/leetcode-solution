class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int ele = INT_MAX;
        for(int i=0; i<prices.size(); i++){
            if(prices[i] < ele){
                ele = prices[i];
            }
            else{
                profit += prices[i]-ele;
                ele = prices[i];
            }
        }
        return profit;
    }
};