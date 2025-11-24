class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int res=0;
        vector<bool> ans;
        for(int i=0; i<nums.size(); i++){
            res = (res*2 + nums[i])%5;
            ans.push_back(res==0);
        }
        return ans;
    }
};