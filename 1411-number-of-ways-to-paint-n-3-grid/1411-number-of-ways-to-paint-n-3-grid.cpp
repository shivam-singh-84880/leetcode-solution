class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;
    string pre[12] = {{"ryr"},{"yry"},{"gry"},{"ryg"},{"yrg"},{"grg"},{"rgr"},{"ygr"},{"gyr"},{"rgy"},{"ygy"},{"gyg"}};
    int find(int n, int prev){
        if(n == 0)return 1;
        if(dp[n][prev] != -1) return dp[n][prev];
        string past = pre[prev];
        long ans=0;
        for(int i=0; i<12; i++){
            if(i == prev) continue;
            string curr = pre[i];
            bool flag = false;
            for(int j=0; j<3; j++){
                if(past[j] == curr[j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans = (ans + find(n-1,i))%mod;
            }
        }
        return dp[n][prev] = ans;
    }

    int numOfWays(int n) {
        long res=0;
        dp.resize(n,vector<int>(12,-1));
        for(int i=0; i<12; i++){
            res = (res + find(n-1,i))%mod;
        }
        return res;
    }
};

//         int mod = 1e9+7;
//         long a3 = 6;
//         long b2 = 6;
//         for(int i=1; i<n; i++){
//             long na3 = (3*a3 + 2*b2)%mod;
//             long nb2 = (2*a3 + 2*b2)%mod;
//             a3 = na3;
//             b2 = nb2;
//         }
//         return (a3+b2)%mod;