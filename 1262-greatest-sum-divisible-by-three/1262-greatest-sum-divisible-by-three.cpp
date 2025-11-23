class Solution {
public:
    int find(int ind, int mod, vector<int>& nums, vector<vector<int>>& dp){
        if(ind == 0){
            if(mod == 0) return 0;
            else return INT_MIN;
        }

        if(dp[ind][mod] != -1)return dp[ind][mod];

        int ntk = find(ind-1, mod, nums,dp);
        int tk = nums[ind-1] + find(ind-1, (mod+nums[ind-1]%3)%3, nums,dp);

        return dp[ind][mod] = max(tk,ntk);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(3,INT_MIN);
        vector<int> curr(3,INT_MIN);
        //return find(n,0,nums,dp);
        prev[0] = 0;
        for(int ind=1; ind<=n; ind++){
            int r = nums[ind-1]%3;
            for(int mod=0; mod<3; mod++){
                int ntk = prev[mod];
                int tk = nums[ind-1] + prev[(mod+r)%3];
                curr[mod] = max(tk,ntk);
            }
            prev = curr;
        }

        return curr[0];

        // int smone = 1e5+7;
        // int smtwo = 1e5+7;
        // int tot = 0;
        // for(auto& num : nums){
        //     tot += num;
        //     if(num%3 == 1){
        //         smtwo = min(smtwo, smone + num);
        //         smone = min(smone, num);
        //     }
        //     if(num%3 == 2){
        //         smone = min(smone, smtwo + num);
        //         smtwo = min(smtwo, num);
        //     }
        // }

        // if(tot%3 == 0)return tot;
        // else if(tot%3 == 1) return tot - smone;
        // else return tot - smtwo;
    }
};