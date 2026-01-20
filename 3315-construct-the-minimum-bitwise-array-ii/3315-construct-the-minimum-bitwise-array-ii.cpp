class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(auto n : nums){
            if(n == 2){
                res.push_back(-1);
                continue;
            }
            for(int i=1; i<32; i++){
                if((n & (1<<i)) == 0){
                    int x = n ^ (1 << (i-1));
                    res.push_back(x);
                    break;
                }
            }
        }
        return res;
    }
};