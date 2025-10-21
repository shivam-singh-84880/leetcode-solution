class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(101,0);
        int ans = 0;
        int cnt = 0;
        for(auto num : nums){
            mp[num]++;
            if(mp[num] == cnt){
                ans++;
            }
            if(mp[num] > cnt){
                cnt = mp[num];
                ans = 1;
            }
        }
        return ans*cnt;
    }
};