class Solution {
public:
    int find(int ind, int prev, vector<int>& nums, int n, vector<vector<int>>& dp){
        if(ind == n)return 0;
        if(dp[ind][prev] != -1)return dp[ind][prev];
        int tk = 0;
        if(prev == n || nums[ind] > nums[prev]){
           tk = 1 + find(ind+1,ind,nums,n,dp); 
        }
        int ntk = find(ind+1,prev,nums,n,dp);
        return dp[ind][prev] = max(tk,ntk);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
//--------------------using binary search-----------------------
        vector<int> temp;
        temp.push_back(nums[0]);

        int len = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
        //--------------printing approach--------------
        // vector<int> dp(n,1);

        // for(int ind=0; ind<n; ind++){
        //     for(int prev=0; prev<ind; prev++){
        //         if(nums[ind] > nums[prev] && 1 + dp[prev] > dp[ind]){
        //             dp[ind] = 1 + dp[prev]; 
        //         }
        //     }
        // }
        // int ans=0;
        // for(int i=0; i<n; i++){
        //     ans = max(dp[i],ans);
        // }
        // return ans;


//-----------------recursive approach---------------------------
        // for(int ind=n-1; ind>=0; ind--){
        //     for(int prev=n; prev>=0; prev--){
        //         int tk = 0;
        //         if(prev == n || nums[ind] > nums[prev]){
        //             tk = 1 + next[ind]; 
        //         }
        //         int ntk = next[prev];
        //         next[prev] = max(tk,ntk);
        //     }
        // }
        // return next[n];
       // return find(0,n,nums,n,dp);
    }
};