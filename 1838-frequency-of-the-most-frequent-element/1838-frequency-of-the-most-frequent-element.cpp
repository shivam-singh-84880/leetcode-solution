class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        long long sum = 0;
        int j=0;
        int i=0;
        while(j<n){
            sum += nums[j];
            if((long long)(j-i+1)*nums[j] - sum > k){
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return j-i;
    }
};