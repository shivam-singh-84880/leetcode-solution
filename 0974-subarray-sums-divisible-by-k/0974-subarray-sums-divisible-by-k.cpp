class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int rem = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans=0;
        for(auto& num : nums){
            rem = (rem + num)%k;
            if(rem < 0) rem += k;
            ans += mp[rem];

            mp[rem]++;
        }

        return ans;
    }
};