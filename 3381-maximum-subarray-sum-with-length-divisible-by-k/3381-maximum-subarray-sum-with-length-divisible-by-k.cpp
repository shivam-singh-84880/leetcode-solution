class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        long long res = LLONG_MIN;
        
        for(int s=0; s<k; s++){
            int i=s;
            int j=s+k-1;
            long long sum=0;
            long long subsum=0;
            while(i < n && j < n){
                subsum = prefix[j] - ((i-1>=0) ? prefix[i-1] : 0);
                sum = max(subsum,subsum+sum);
                res = max(sum,res);
                i += k;
                j = i+k-1;
            }
        }
        return res;

    }
};