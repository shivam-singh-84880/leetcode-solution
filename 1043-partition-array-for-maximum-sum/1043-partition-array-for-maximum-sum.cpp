class Solution {
public:
    int find(int i, int n, int k, vector<int>& arr){
        if(i >= n)return 0;
        int res = 0;
        int maxi = 0;
        int ans = 0;
        for(int j=i; j<min(k+i,n); j++){
            maxi = max(maxi,arr[j]);
            ans = maxi*(j-i+1) + find(j+1,n,k,arr);
            res = max(ans,res);
        }
        return res;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int i=n-1; i>=0; i--){
            int res = 0;
            int maxi = 0;
            int ans = 0;
            for(int j=i; j<min(k+i,n); j++){
                maxi = max(maxi,arr[j]);
                ans = maxi*(j-i+1) + dp[j+1];
                res = max(ans,res);
            }
            dp[i] = res;
        }
        return dp[0];
        //return find(0,n,k,arr);
    }
};