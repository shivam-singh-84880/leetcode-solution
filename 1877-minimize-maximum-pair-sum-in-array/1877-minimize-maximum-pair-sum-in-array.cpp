class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0;
        int j=nums.size()-1;
        int maxi=INT_MIN;
        while(i < j){
            maxi = max(maxi,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};