class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size();
        int n2 = str2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string ans = "";
        while(n1 > 0 && n2 > 0){
            if(str1[n1-1] == str2[n2-1]){
                ans += str1[n1-1];
                n1 -= 1;
                n2 -= 1;
            }
            else if(dp[n1-1][n2] > dp[n1][n2-1]){
                ans += str1[n1-1];
                n1--;
            }
            else{
                ans += str2[n2-1];
                n2--;
            }
        }
        while(n1 > 0){
            ans += str1[n1-1];
            n1--;
        }
        while(n2 > 0){
            ans += str2[n2-1];
            n2--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

