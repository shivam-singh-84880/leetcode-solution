class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int,int> freq;
        map<int,int> prefix;
        set<int> points;
        for(auto num : nums){
            freq[num]++;
            prefix[num-k]++;
            prefix[num+k+1]--;
            points.insert(num);
            points.insert(num-k);
            points.insert(num+k+1);
        }
        
        int sum=0;
        int ans=1;
        for(auto point : points){
            sum += prefix[point];
            int f = freq[point];
            ans = max(ans, f + min(sum-f,numOperations));
        }
        return ans;
    }
};