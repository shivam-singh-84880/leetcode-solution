class Solution {
public:
    int find(int ind, int t, vector<int>& nums,vector<vector<int>>& dp){
        if(t == 0)return true;
        if(ind == 0){
            return (t == nums[0]);
        }
        if(dp[ind][t] != -1)return dp[ind][t];
        bool tk = false;
        if(t >= nums[ind]){
            tk = find(ind-1,t-nums[ind],nums,dp);
        }
        bool ntk = find(ind-1,t,nums,dp);
        return dp[ind][t] = (tk || ntk);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        if(sum&1) return false;
        int t = sum/2;
        vector<vector<int>> dp(n,vector<int>(t+1,-1));
        return find(n-1,sum/2,nums,dp);
    }
};