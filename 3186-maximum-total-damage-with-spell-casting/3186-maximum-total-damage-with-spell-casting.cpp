class Solution {
public:
    int find(int ind, int prev, int& n, vector<int>& power, vector<vector<int>>& dp){
        if(ind >= n)return 0;
        if(dp[ind][prev] != -1)return dp[ind][prev];
        int tk = 0;
        if(prev == n || (power[prev] + 1 != power[ind] && power[prev]+2 != power[ind])){
            // take
            tk = power[ind] + find(ind+1,ind,n,power,dp);
        }
        //not take
        int ntk = find(ind+1,prev,n,power,dp);
        return dp[ind][prev] = max(tk,ntk);
    }

    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int,long long> freq;
        for(auto x : power){
            freq[x] += x;
        }
        vector<int> keys;
        for(auto &[x,val] : freq){
            keys.push_back(x);
        }
        sort(keys.begin(),keys.end());
        int n = keys.size();
        vector<long long> dp(n,0);
        for(int i=0; i<n; i++){
            long long val = freq[keys[i]];
            int j = i-1;
            while(j>=0 && keys[j]+2 >= keys[i]){
                j--;
            }
            if(j>=0){
                dp[i] = val + dp[j];
            }
            else dp[i] = val;
            if(i>0) dp[i] = max(dp[i],dp[i-1]);
        }
        return dp[n-1];
    }
};
