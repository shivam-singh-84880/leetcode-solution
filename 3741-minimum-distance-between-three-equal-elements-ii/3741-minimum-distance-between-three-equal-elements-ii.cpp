class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,array<int,3>> dt;
        int ans = INT_MAX;
        int ele=0;
        for(int i=0; i<n; i++){
            ele = nums[i];
            auto& ref = dt[ele];

            if(ref[0] == 0){
                ref[0] = 1;
                ref[1] = i;
            }
            else if(ref[0] == 1){
                ref[0] = 2;
                ref[2] = i;
            }

            else {
                ans = min(ans, 2*(i-ref[1]));
                ref[1] = ref[2];
                ref[2] = i;
            }
            
        }
        if(ans != INT_MAX) return ans;
        else return -1;
    }
};