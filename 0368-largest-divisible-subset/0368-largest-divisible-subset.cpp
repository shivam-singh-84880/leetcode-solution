class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> hash(n,-1);
        int maxi = 0;
        int ind = 0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j] == 0 && 1 + dp[j] > dp[i]){
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                ind = i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[ind]);
        while(hash[ind] != ind){
            ans.push_back(nums[hash[ind]]);
            ind = hash[ind];
        }
        return ans;
    }
};