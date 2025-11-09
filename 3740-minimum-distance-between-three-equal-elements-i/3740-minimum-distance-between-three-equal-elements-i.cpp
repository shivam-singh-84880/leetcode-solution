class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> dt(n+1,{0,0});
        int ans = INT_MAX;
        int ele=0;
        for(int i=0; i<n; i++){
            ele = nums[i];
            dt[ele].first++;

            if(dt[ele].first == 1){
                dt[ele].second = i;
            }

            if(dt[ele].first >= 3){
                ans = min(ans, 2*(i-dt[ele].second));
            }
            
        }
        if(ans != INT_MAX) return ans;
        else return -1;
    }
};