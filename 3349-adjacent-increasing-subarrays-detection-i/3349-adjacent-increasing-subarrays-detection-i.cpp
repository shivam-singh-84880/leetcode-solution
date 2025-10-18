class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
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
            if(mlen >= k)return true;
        }
        return false;
    }
};