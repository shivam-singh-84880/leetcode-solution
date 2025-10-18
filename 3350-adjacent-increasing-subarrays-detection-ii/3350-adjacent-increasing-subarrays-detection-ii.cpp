class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int ccnt = 1;
        int pcnt = 0;
        int mlen = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] < nums[i]){
                ccnt++;
            }
            else{
                pcnt = ccnt;
                ccnt = 1;
            }
            mlen = max(mlen,max(ccnt/2,min(pcnt,ccnt)));
        }
        return mlen;
    }
};