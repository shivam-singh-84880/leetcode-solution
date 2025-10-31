class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size()-2;
        int x=0;
        for(auto num : nums){
            x ^= num;
        }
        for(int i=0; i<n; i++){
            x ^= i;
        }
        int lastsetbit = (x & x-1)^x;
        int b1=0, b2=0;
        for(auto num:nums){
            if(num & lastsetbit) b1 ^= num;
            else b2 ^= num;
        }
        for(int i=0; i<n; i++){
            if(i & lastsetbit) b1 ^= i;
            else b2 ^= i;
        }
        return {b1,b2};
    }
};