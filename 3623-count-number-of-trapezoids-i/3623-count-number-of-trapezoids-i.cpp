class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,long long> mp;
        int mod = 1e9+7;
        for(auto& pt : points){
            mp[pt[1]]++;
        }
        for(auto& [pt,val] : mp){
            long long sum = val*(val-1)/2;
            mp[pt] = sum;
        }
        int ans=0;
        int sum=0;
        for(auto& [pt,val] : mp){
            ans = (ans + (sum*val)%mod)%mod;
            sum += val;
        }
        return ans;
    }
};