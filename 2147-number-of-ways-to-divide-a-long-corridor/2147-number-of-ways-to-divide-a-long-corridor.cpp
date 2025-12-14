class Solution {
public:
    int find(string& c, int ind, int cnt, int& n, vector<vector<int>>& dp){
        if(cnt > 2)return 0;
        if(ind >= n) return cnt == 2;
        int ans=0;
        if(dp[ind][cnt] != -1)return dp[ind][cnt];
        if(c[ind] == 'S'){
            ans += find(c,ind+1,cnt+1,n,dp);
            if(cnt == 2){
                ans += find(c,ind+1,1,n,dp);
            }
        }
        else{
            ans += find(c,ind+1,cnt,n,dp);
            if(cnt == 2){
                ans += find(c,ind+1,0,n,dp);
            }
        }
        return dp[ind][cnt] = ans;
    }
    int numberOfWays(string c) {
        int n = c.size();
        int mod = 1e9+7;
        int j=0;
        int k=0;
        int ans=1;
        for(int i=0; i<n; i++){
            if(c[i] == 'S'){
                k++;
                if(k>2 && k%2 == 1){
                    ans = (1ll * ans * (i-j))%mod;
                }
                j=i;
            }
        }
        return k>0 && k%2==0 ? ans : 0;
        //vector<vector<int>> dp(n+1,vector<int>(3,0));
        // vector<int> curr(3,0);
        // vector<int> next(3,0);
        // next[2] = 1;
        // for(int ind=n-1; ind>=0; ind--){
        //     for(int cnt=2; cnt>=0; cnt--){
        //         long long ans=0;
        //         if(c[ind] == 'S'){
        //             ans += (cnt + 1 <= 2) ? next[cnt+1] : 0;
        //             if(cnt == 2){
        //                 ans += next[1];
        //             }
        //         }
        //         else{
        //             ans += next[cnt];
        //             if(cnt == 2){
        //                 ans += next[0];
        //             }
        //         }
        //         ans %= mod;
        //         curr[cnt] = ans;
        //     }
        //     next = curr;
        // }
        //return find(c,0,0,n,dp);

        //return next[0];
    }
};
