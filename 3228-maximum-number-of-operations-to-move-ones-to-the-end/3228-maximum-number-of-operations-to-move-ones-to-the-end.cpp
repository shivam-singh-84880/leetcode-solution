class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
        int cnt = s[0] == '1';
        int ans = 0;
        for(int i=1; i<n; i++){
            if(s[i] == '1') cnt++;
            else if(s[i-1] == '1') ans += cnt;
        }
        return ans;
    }
};