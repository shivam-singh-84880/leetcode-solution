class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int bit=0;
        for(auto& num : nums){
            if(num%original == 0){
                num = num / original;
                if((num & (num-1)) == 0){
                    bit |= num;
                }
            }
        }
         int ans = bit + 1;
         return original * (ans & -ans);
    }
};