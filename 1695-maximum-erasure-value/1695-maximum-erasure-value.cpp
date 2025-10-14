class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0;
        int i=0;
        int j=0;
        int n = nums.size();
        int ans = 0;
        unordered_set<int> st;
        while(j<n){
            while(st.find(nums[j]) != st.end()){
                sum = sum - nums[i];
                st.erase(nums[i]);
                i++;
            }
            st.insert(nums[j]);
            sum += nums[j];
            ans = max(sum,ans);
            j++;
        }
        return ans;
    }
};