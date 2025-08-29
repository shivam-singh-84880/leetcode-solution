class Solution {
public:
    bool find(int inds, int indp, string& s, string& p, vector<vector<int>>& dp){
        if(inds == 0 && indp == 0) return 1;
        if(indp == 0 && inds > 0) return 0;
        if(inds == 0 && indp > 0){
            for(int i=1; i<=indp; i++){
                if(p[i-1] != '*')return 0;
            }
            return 1;
        }
        if(dp[inds][indp] != -1)return dp[inds][indp];
        if(s[inds-1] == p[indp-1] || p[indp-1] == '?'){
            return dp[inds][indp] = find(inds-1,indp-1,s,p,dp);
        }
        else if(p[indp-1] == '*'){
            return dp[inds][indp] = find(inds-1,indp,s,p,dp) || find(inds,indp-1,s,p,dp);
        }
        else return 0;
    }   

    bool isMatch(string s, string p) {
        int ns = s.size();
        int np = p.size();
        vector<int> curr(np+1,0);
        vector<int> prev(np+1,0);
        prev[0] = 1;
        for(int i=1; i<=np; i++){
            if(p[i-1] == '*'){
                prev[i] = 1;
            }
            else{
                break;
            }
        }
        for(int inds=1; inds<=ns; inds++){
            for(int indp=1; indp<=np; indp++){
                if(s[inds-1] == p[indp-1] || p[indp-1] == '?'){
                    curr[indp] = prev[indp-1];
                }
                else if(p[indp-1] == '*'){
                    curr[indp] = prev[indp] || curr[indp-1];
                }
                else curr[indp] = 0;
            }
            prev = curr;
        }
        return prev[np];
        //return find(ns,np,s,p,dp);
    }
};