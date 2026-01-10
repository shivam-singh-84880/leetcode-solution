class Solution {
public:
    int dp[1001][1001];
    int find(int i, int j, string& s1, string& s2){
        if(i <= 0 && j <= 0){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(j <= 0){
            return dp[i][j] = s1[i-1] + find(i-1, j, s1, s2);
        }
        if(i <= 0){
            return dp[i][j] = s2[j-1] + find(i, j-1, s1, s2);
        }
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = find(i-1, j-1, s1, s2);
        }

        int mini = s1[i-1] + find(i-1, j, s1, s2);
        int minj = s2[j-1] + find(i, j-1, s1, s2);

        return dp[i][j] = min(mini,minj);
    }

    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        memset(dp,-1,sizeof(dp));
        return find(n1, n2, s1,s2);
    }
};