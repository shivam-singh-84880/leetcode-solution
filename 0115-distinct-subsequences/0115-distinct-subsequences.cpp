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
        vector<long long> prev(nt+1,0);
        vector<long long> curr(nt+1,0);
        long long tk = 0;
        for(int i=1; i<=ns; i++){
            prev[0] = 1;
            for(int j=1; j<=nt; j++){
                tk = 0;
                if(s[i-1] == t[j-1]){
                    tk = prev[j-1];
                }
                curr[j] = tk + prev[j];
            }
            prev = curr;
        }
        return (int)prev[nt];
        //return find(ns,nt,s,t,dp);
    }
};