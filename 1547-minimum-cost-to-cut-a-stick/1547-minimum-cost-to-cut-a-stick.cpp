class Solution {
public:
    int find(int i, int j, vector<int>& cuts,vector<vector<int>>& dp){
        if(i > j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int mini = INT_MAX;
        for(int k=i; k<=j; k++){
            int ans = cuts[j+1] - cuts[i-1] + find(i,k-1,cuts,dp) + find(k+1,j,cuts,dp);
            mini = min(ans,mini);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int clen = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        vector<vector<int>> dp(clen+1,vector<int>(clen+1,-1));
        return find(1,clen,cuts,dp);
    }
};