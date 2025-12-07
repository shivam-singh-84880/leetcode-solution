class Solution {
public:
    // int countPartitions(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     vector<int> dp(n+1,0);
    //     int mod = 1e9+7;
    //     dp[n] = 1;
    //     for(int i=n-1; i>=0; i--){
    //         int cnt=0;
    //         int mini = INT_MAX;
    //         int maxi = INT_MIN;
    //         for(int j=i; j<n; j++){
    //             mini = min(mini,nums[j]);
    //             maxi = max(maxi,nums[j]);
    //             if(maxi - mini > k) break;
    //             else {
    //                 cnt = (cnt + dp[j+1])%mod;
    //             }
    //         }
    //         dp[i] = cnt;
    //     }
    //     return dp[0];
    // }


    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int mod=1e9+7;
        deque<int> maxi;
        deque<int> mini;
        vector<int> dp(n+1,0);
        vector<int> prefix(n+1,0);
        dp[0]=1;
        prefix[0]=1;
        int i=0, j=0;
        while(j<n){
            while(!maxi.empty() && nums[j] >= nums[maxi.back()] ){
                maxi.pop_back();
            }
            maxi.push_back(j);

            while(!mini.empty() && nums[j] <= nums[mini.back()]){
                mini.pop_back();
            }
            mini.push_back(j);

            while(i<=j && (nums[maxi.front()] - nums[mini.front()]) > k){
                i++;
                if(i > maxi.front())maxi.pop_front();
                if(i > mini.front())mini.pop_front();
            }

            dp[j+1] = (prefix[j] - (i>0 ? prefix[i-1] : 0) + mod)%mod;
            prefix[j+1] = (prefix[j] + dp[j+1])%mod;
            j++;
        }
        return dp[n];
    }
};