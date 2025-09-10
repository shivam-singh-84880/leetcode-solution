class Solution {
public:
    bool ispal(int st, int e, string& s){
        while(st < e){
            if(s[st] != s[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }

    int find(int i, int j, string& s, vector<int>& dp){
        if(i == j)return 0;
        if(dp[i] != -1)return dp[i];
        int mini = INT_MAX;
        for(int k=i; k<j; k++){
            if(ispal(i,k,s)){
                int ans = 1 + find(k+1,j,s,dp);
                mini = min(mini,ans);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            int mini = INT_MAX;
            for(int k=i; k<n; k++){
                if(ispal(i,k,s)){
                    int ans = 1 + dp[k+1];
                    mini = min(mini,ans);
                }
            }
            dp[i] = mini;
        }
        return dp[0]-1;
        //return find(0,n,s,dp)-1;
    }
};