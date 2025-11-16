class Solution {
public:
    int numSub(string s) {
        int n = s.size();
        int ans=0;
        int i=0;
        int mod = 1e9+7;
        while(i<n){
            while(i<n && s[i]=='0'){
                i++;
            }
            int cnt=0;
            while(i<n && s[i] == '1'){
                cnt++;
                i++;
            }
            ans = (ans + (long long)cnt*(cnt+1)/2)%mod;
        }
        return ans;
    }
};