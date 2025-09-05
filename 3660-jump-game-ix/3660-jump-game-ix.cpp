class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxi(n,0);
        vector<int> mini(n,0);
        vector<int> ans(n,0);
        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];
        for(int i=1; i<n; i++){
            maxi[i] = max(maxi[i-1],nums[i]);
            mini[n-i-1] = min(mini[n-i],nums[n-i-1]);
        }
        ans[n-1] = maxi[n-1];
        for(int i=n-2; i>=0; i--){
            if(maxi[i] > mini[i+1]){
                ans[i] = ans[i+1];
            }
            else{
                ans[i] = maxi[i];
            }
        }
        return ans;
    }
};