class Solution {
public:
    int find(int n1, int n2, string& text1, string& text2, vector<vector<int>>& dp){
        if(n1 == 0 || n2 == 0) return 0;
        if(dp[n1][n2] != -1) return dp[n1][n2];
        if(text1[n1-1] == text2[n2-1]){
            return dp[n1][n2] = 1 + find(n1-1,n2-1,text1,text2,dp);
        }
        else{
            return dp[n1][n2] = max(find(n1-1,n2,text1,text2,dp),find(n1,n2-1,text1,text2,dp));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return find(n1,n2,text1,text2,dp);
    }
};