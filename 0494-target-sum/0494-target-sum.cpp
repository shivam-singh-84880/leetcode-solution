class Solution {
public:
    int find(int ind, int t, vector<int>& arr){
        if(ind == 0){
            if(t==0 && arr[0]==0)return 2;
            if(t==0 || t == arr[0])return 1;
            else return 0;
        }
        int tk = 0;
        if(t >= arr[ind]){
            tk = find(ind-1,t-arr[ind],arr);
        }
        int ntk = find(ind-1,t,arr);
        return tk+ntk;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        
        int t = (sum - target)/2;
        if((sum-target)%2==1)return 0;
        else if(sum-target < 0)return 0;
        else{
            return find(n-1,t,nums);
        }
    }
};