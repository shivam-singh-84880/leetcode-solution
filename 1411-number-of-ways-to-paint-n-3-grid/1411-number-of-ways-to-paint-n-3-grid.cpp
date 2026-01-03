class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9+7;
        long a3 = 6;
        long b2 = 6;
        for(int i=1; i<n; i++){
            long na3 = (3*a3 + 2*b2)%mod;
            long nb2 = (2*a3 + 2*b2)%mod;
            a3 = na3;
            b2 = nb2;
        }
        return (a3+b2)%mod;
    }
};