class Solution {
public:
    int mod = 1e9+7;
    long long power(long long x, long long y){
        int res = 1;
        while(y > 0){
            if(y&1){
                res = (res*x)%mod;
                y -= 1;
            }
            else{
                x = (x*x)%mod;
                y = y>>1;
            }
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long c4 = n/2;
        long long c5 = n - c4;
        long long ans = (power(5,c5)%mod * power(4,c4)%mod)%mod;
        return ans;
    }
};