class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int mini = INT_MAX;
        for(int i=0; i+k<=n; i++){
            mini = min(mini, nums[i+k-1] - nums[i]);
        }
        return mini;
    }
};