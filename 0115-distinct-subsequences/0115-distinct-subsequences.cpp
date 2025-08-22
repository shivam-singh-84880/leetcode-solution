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
        vector<vector<int>> dp(ns+1,vector<int>(nt+1,-1));
        return find(ns,nt,s,t,dp);
    }
};