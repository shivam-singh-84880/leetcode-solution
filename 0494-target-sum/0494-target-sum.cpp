class Solution {
public:
    // int find(int ind, int t, vector<int>& arr, vector<vector<int>>& dp){
    //     if(ind == 0){
    //         if(t==0 && arr[0]==0)return 2;
    //         if(t==0 || t == arr[0])return 1;
    //         else return 0;
    //     }
    //     if(dp[ind][t] != -1)return dp[ind][t];
    //     int tk = 0;
    //     if(t >= arr[ind]){
    //         tk = find(ind-1,t-arr[ind],arr,dp);
    //     }
    //     int ntk = find(ind-1,t,arr,dp);
    //     return dp[ind][t] =  tk+ntk;
    // }
    int find(int ind, int& t, int sum, vector<int>& nums, vector<unordered_map<int,int>>& mp){
        if(ind < 0){
            return sum == t ? 1 : 0;
        }
        if(mp[ind].count(sum))return mp[ind][sum];
        int pos = find(ind-1,t,sum+nums[ind],nums,mp);
        int neg = find(ind-1,t,sum-nums[ind],nums,mp);
        return mp[ind][sum] =  pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int,int>> mp(n);
        return find(n-1,target,0,nums,mp);
        // int n = nums.size();
        // int sum = 0;
        // for(auto num : nums){
        //     sum += num;
        // }
        // int t = 0;
        // if(target < 0){
        //     t = (sum + target)/2;
        // }
        // else{
        //     t = (sum - target)/2;
        // }
        // if((sum-target)%2==1)return 0;
        // else if(sum-target < 0 || sum + target < 0)return 0;
        // else{
        //     vector<vector<int>> dp(n,vector<int>(t+1,-1));
        //     return find(n-1,t,nums,dp);
        // }
    }
};