class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        int len=0;
        while(j<n){
            if(nums[j]==0)cnt++;
            if(cnt>1){
                if(nums[i]==0){
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return j-i-1;
    }
};