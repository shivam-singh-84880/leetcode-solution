class Solution {
public:
    bool find(int inds, int indp, string& s, string& p, vector<vector<int>>& dp){
        if(inds == 0 && indp == 0) return true;
        if(indp == 0 && inds > 0) return false;
        if(inds == 0 && indp > 0){
            for(int i=1; i<=indp; i++){
                if(p[i-1] != '*')return false;
            }
            return true;
        }
        if(dp[inds][indp] != -1)return dp[inds][indp];
        if(s[inds-1] == p[indp-1] || p[indp-1] == '?'){
            return dp[inds][indp] = find(inds-1,indp-1,s,p,dp);
        }
        else if(p[indp-1] == '*'){
            return dp[inds][indp] = find(inds-1,indp,s,p,dp) || find(inds,indp-1,s,p,dp);
        }
        else return false;
    }   

    bool isMatch(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<vector<int>> dp(ns+1,vector<int>(np+1,-1));
        return find(ns,np,s,p,dp);
    }
};