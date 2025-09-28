class Solution {
public:
    void find(int& n, vector<int>& temp, vector<int>& vis, vector<vector<int>>& ans, vector<int>& nums){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(!vis[i]){
                vis[i] = 1;
                temp.push_back(nums[i]);
                find(n,temp,vis,ans,nums);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        find(n,temp,vis,ans,nums);
        return ans;
    }
};