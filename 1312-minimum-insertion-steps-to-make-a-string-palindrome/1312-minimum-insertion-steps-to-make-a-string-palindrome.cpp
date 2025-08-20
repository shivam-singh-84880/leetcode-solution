class Solution {
public:
    int find(int ind, int ind1, string& s, string& s1,vector<vector<int>>& dp){
        if(ind == 0 || ind1 == 0)return 0;
        if(dp[ind][ind1] != -1)return dp[ind][ind1];
        if(s[ind-1] == s1[ind1-1]){
            return dp[ind][ind1] = 1 + find(ind-1,ind1-1,s,s1,dp);
        }
        else{
            return dp[ind][ind1] = max(find(ind-1,ind1,s,s1,dp),find(ind,ind1-1,s,s1,dp));
        }
    }

    int minInsertions(string s) {
        int n = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int len = find(n,n,s,s1,dp);
        return n - len;
    }
};