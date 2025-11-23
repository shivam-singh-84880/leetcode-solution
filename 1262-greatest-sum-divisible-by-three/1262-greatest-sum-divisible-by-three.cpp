class Solution {
public:
    int find(int ind, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(ind < 0){
            if(sum%3 == 0) return sum;
            else return 0;
        }

        if(dp[ind][sum] != -1)return dp[ind][sum];

        int ntk = find(ind-1, sum, nums,dp);
        int tk = find(ind-1, sum+nums[ind], nums,dp);

        return dp[ind][sum] = max(tk,ntk);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int ts = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(n,vector<int>(ts+1,-1));
        return find(n-1,0,nums,dp);
    }
};