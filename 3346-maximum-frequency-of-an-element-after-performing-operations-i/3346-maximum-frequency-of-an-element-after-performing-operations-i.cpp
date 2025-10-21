class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxele = *max_element(nums.begin(),nums.end());
        vector<int> freq(maxele+1,0);
        vector<int> prefix(maxele+1,0);
        int ans=0;
        for(auto ele : nums){
            freq[ele]++;
        }
        for(auto x : nums){
            if(x-k > 0)prefix[x-k]++;
            else prefix[0]++;
            if(x+k+1 <= maxele)prefix[x+k+1]--;
        }
        for(int x=1; x<=maxele; x++){
            prefix[x] += prefix[x-1];
            int f = freq[x];
            ans = max(ans, f + min(prefix[x]-f,numOperations));
        }
        return ans;
    }
};