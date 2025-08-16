class Solution {
public:
    int find(int ind, int t, vector<int>& arr, vector<vector<int>>& dp){
        if(ind == 0){
            if(t==0 && arr[0]==0)return 2;
            if(t==0 || t == arr[0])return 1;
            else return 0;
        }
        if(dp[ind][t] != -1)return dp[ind][t];
        int tk = 0;
        if(t >= arr[ind]){
            tk = find(ind-1,t-arr[ind],arr,dp);
        }
        int ntk = find(ind-1,t,arr,dp);
        return dp[ind][t] =  tk+ntk;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        int t = 0;
        if(target < 0){
            t = (sum + target)/2;
        }
        else{
            t = (sum - target)/2;
        }
        if((sum-target)%2==1)return 0;
        else if(sum-target < 0 || sum + target < 0)return 0;
        else{
            vector<vector<int>> dp(n,vector<int>(t+1,-1));
            return find(n-1,t,nums,dp);
        }
    }
};