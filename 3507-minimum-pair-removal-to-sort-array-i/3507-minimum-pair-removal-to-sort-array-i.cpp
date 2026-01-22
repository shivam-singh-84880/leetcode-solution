class Solution {
public:
    int get(vector<int>& nums){
        int sum = INT_MAX;
        int ind=0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + nums[i+1] < sum){
                sum = nums[i] + nums[i+1];
                ind = i;
            }
        }
        return ind;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int cnt=0;
        while(!is_sorted(begin(nums),end(nums))){
            int ind = get(nums);
            nums[ind] += nums[ind+1];
            nums.erase(nums.begin()+ind+1);
            cnt++;
        }
        return cnt;
    }
};