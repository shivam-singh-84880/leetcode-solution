class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans=0;
        int n = prices.size();
        int i=0;
        int j=0;
        while(i < n){
            if( i > 0 && (prices[i-1] - prices[i] != 1)){
                j = i;
            }
            ans += i-j+1;
            i++;
        }
        return ans;
    }
};