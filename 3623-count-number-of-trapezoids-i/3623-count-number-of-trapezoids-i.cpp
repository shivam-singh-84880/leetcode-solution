class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long> mp;
        int mod = 1e9+7;
        for(auto& pt : points){
            mp[pt[1]]++;
        }
        long long ans=0;
        long long phline=0;
        for(auto& [pt,val] : mp){
            long long hl = val*(val-1)/2;
            ans += hl*phline;
            phline += hl;
        }
        return ans%mod;
    }
};