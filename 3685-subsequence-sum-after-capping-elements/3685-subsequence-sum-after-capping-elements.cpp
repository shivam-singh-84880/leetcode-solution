class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
        sort(nums.begin(),nums.end());
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }

        for(int i=1; i<=n; i++){
            for(int t=1; t<=k; t++){
                dp[i][t] = dp[i-1][t];
                if(nums[i-1] <= t){
                    dp[i][t] = dp[i][t] | dp[i-1][t-nums[i-1]];
                }
            }
        }

        vector<bool> ans(n,false);
        for(int x=1; x<=n; x++){
            int ind = lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            int nrele = n-ind;
            for(int i=0; i<=nrele; i++){
                int rm = k-x*i;
                if(rm >= 0 && dp[ind][rm]){
                    ans[x-1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};
// vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<bool> ans(n,false);
//         vector<int> temp;

//         for(int x=1; x<=n; x++){
//             for(int i=0; i<n; i++){
//                 temp.push_back(min(x,nums[i]));
//             }
//             vector<bool> dp(k+1,false);
//             dp[0] = true;
//             for(int ind=0; ind<n; ind++){
//                 for(int sum=k; sum>=temp[ind]; sum--){
//                     dp[sum] = dp[sum] || dp[sum-temp[ind]];
//                 }
//             }

//             if(dp[k]){
//                 ans[x-1] = true;
//             }
//             temp = {};
//         }

//         return ans;
//     }