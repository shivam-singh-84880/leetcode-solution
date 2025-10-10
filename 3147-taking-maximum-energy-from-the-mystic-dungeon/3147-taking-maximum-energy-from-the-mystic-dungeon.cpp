class Solution {
public:
    int solve(vector<int>& energy, int ind, int& k){
        if(ind >= energy.size())return 0;
        
        return energy[ind] + solve(energy,ind+k,k);
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        vector<int> dp(n,INT_MIN);

        for(int i=n-1; i>=0; i--){
            if(i+k >= n){
                dp[i] = energy[i];
            }
            else dp[i] = energy[i] + dp[i+k];
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};