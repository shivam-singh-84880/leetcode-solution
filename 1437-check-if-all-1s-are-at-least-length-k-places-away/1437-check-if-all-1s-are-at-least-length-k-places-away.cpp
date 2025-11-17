class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int i=-1;
        int j=0;
        if(nums[0] == 1){
            j=1;
            i=0;
        }
        while(j<n){
            if(nums[j] == 0){
                j++;
            }
            else if(j-i-1 >= k || i == -1){
                i = j;
                j++;
            }
            else return false;
        }
        return true;
    }
};