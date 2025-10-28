class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = nums[i] + prefix[i-1];
        }

        int suffix = 0;
        int cnt = 0;
        for(int i=n-1; i>=0; i--){
            suffix += nums[i];
            if(nums[i] == 0){
                if(prefix[i] == suffix){
                    cnt += 2;
                }
                else if(prefix[i]+1 == suffix || suffix + 1 == prefix[i]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};