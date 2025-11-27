class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum=0;
        int maxsum=0;
        int res=0;
        for(auto& num : nums){
            maxsum = max(num,maxsum+num);
            minsum = min(num,minsum+num);
            res = max(res,max(maxsum,abs(minsum)));
        }
        return res;
    }
};