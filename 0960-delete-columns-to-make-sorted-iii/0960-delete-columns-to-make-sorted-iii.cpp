class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<int> dp(m,1);
        for(int i=1; i<m; i++){
            for(int j=0; j<i; j++){
                bool t = true;
                for(int k=0; k<n; k++){
                    if(strs[k][j] > strs[k][i]){
                        t = false;
                        break;
                    }
                }
                if(t) dp[i] = max(dp[i],dp[j]+1);
            }
        }
        int maxi = 0;
        for(auto &num : dp){
            maxi = max(maxi,num);
        }
        return m - maxi;
    }
};
