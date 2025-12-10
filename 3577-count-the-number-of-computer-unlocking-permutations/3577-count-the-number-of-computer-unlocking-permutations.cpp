class Solution {
public:
    int countPermutations(vector<int>& c) {
        int mini = *min_element(c.begin()+1, c.end());
        if(c[0] >= mini)return 0;
        long long ans=1;
        int mod=1e9+7;
        for(int i=1; i<c.size(); i++){
            ans = ans*i;
            ans %= mod;
        }
        return ans;
    }
};