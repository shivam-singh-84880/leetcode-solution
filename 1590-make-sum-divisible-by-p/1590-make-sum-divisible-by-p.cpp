class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int prem=0;
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(auto& num: nums){
            prem = (prem + num)%p;
        }

        if(prem == 0)return 0;
        int rem = 0;

        for(int i=0; i<n; i++){
            rem = (rem + nums[i])%p;
            int need = (rem - prem + p)%p;
            if(mp.find(need) != mp.end()){
                ans = min(ans, i - mp[need]);
            }
            mp[rem] = i;
        }
        if(ans == n)return -1;
        else return ans;
    }
};