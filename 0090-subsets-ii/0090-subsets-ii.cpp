class Solution {
public:
    vector<vector<int>> ans;
    void find(int ind, int& n, vector<int> path, vector<int>& nums){
        ans.push_back(path);
        for(int i=ind; i<n; i++){
            if(i > ind && nums[i-1] == nums[i])continue;
            path.push_back(nums[i]);
            find(i+1,n,path,nums);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        find(0,n,path,nums);
        return ans;
    }
};