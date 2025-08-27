class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0)return false;
        int ngf = n/k;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > ngf){
                return false;
            }
        }
        return true;
    }
};