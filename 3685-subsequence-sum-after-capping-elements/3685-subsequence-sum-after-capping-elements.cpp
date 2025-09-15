class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        vector<bool> dp(k+1,false);
        dp[0] = true;
        vector<bool> ans(n,false);
        for(int x=1; x<=n; x++){
            int i=0;
            while(i<n && nums[i]<x){
                for(int t=nums[i]; t<=k; t++){
                    dp[t] = dp[t] | dp[t-nums[i]];
                }
                i++;
            }
            int nrele = n-i;
            for(int i=0; i<=nrele; i++){
                int rm = k-x*i;
                if(rm >= 0 && dp[rm]){
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