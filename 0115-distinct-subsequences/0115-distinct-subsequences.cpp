class Solution {
public:
    int find(int ns, int nt, string& s, string& t, vector<vector<int>>& dp){
        if(nt == 0)return 1;
        if(ns == 0)return 0;
        if(dp[ns][nt] != -1)return dp[ns][nt];
        int tk = 0;
        if(s[ns-1] == t[nt-1]){
            tk = find(ns-1,nt-1,s,t,dp);
        }
        return dp[ns][nt] = tk + find(ns-1,nt,s,t,dp);

    }

    int numDistinct(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        vector<long long> curr(nt+1,0);
        curr[0] = 1;
        long long tk = 0;
        for(int i=1; i<=ns; i++){
            for(int j=nt; j>0; j--){
                tk = 0;
                if(s[i-1] == t[j-1]){
                    tk = curr[j-1];
                }
                curr[j] = (tk + curr[j])%INT_MAX;
            }
        }
        return curr[nt];
        //return find(ns,nt,s,t,dp);
    }
};