class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> l,r;
        int ans = 0;
        int mod = 1e9+7;
        for(auto& num : nums){
            ans = (ans + r[num/2])%mod;
            r[num] = (r[num] + l[num*2])%mod;
            l[num]++;
        }
        return ans;

        // unordered_map<int,int> l,r;
        // int ans=0;
        // int mod=1e9+7;
        // for(auto& num : nums){
        //     r[num]++;
        // }
        // for(auto& num : nums){
        //     r[num]--;
        //     ans = (ans + (1ll * r[num*2] * l[num*2])%mod)%mod;
        //     l[num]++;
        // }
        // return ans;
    }
};