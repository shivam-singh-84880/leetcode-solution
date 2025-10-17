class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        nums.erase(unique(nums.begin(),nums.end()),nums.end());
        int m = nums.size();
        int j=0;
        int i=0;
        int ans=0;
        while(j<m){
            if(nums[j]-nums[i] >= n){
                i++;
            }
            j++;
        }
        return n-j+i;
    }
};