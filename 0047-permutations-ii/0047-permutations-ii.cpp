class Solution {
public:
    vector<vector<int>> ans;
    void find1(int ind, vector<int> nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<nums.size(); i++){
            if(i != ind && nums[i] == nums[ind])continue;
            swap(nums[i],nums[ind]);
            find1(ind+1,nums);
            //swap(nums[i],nums[ind]); ->1 2 2 -> fail if swap on backtrack.
        }

    }

    void find(vector<int>temp, vector<int>& nums, vector<int>& vis,int& n){
        if(temp.size() == n){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<n; i++){
            if(vis[i] || i>0 && nums[i-1]==nums[i] && !vis[i-1])continue;
            vis[i] = 1;
            temp.push_back(nums[i]);
            find(temp,nums,vis,n);
            vis[i] = 0;
            temp.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //find1(0,nums);
        vector<int> temp;
        vector<int> vis(n,0);
        find(temp,nums,vis,n);
        return ans;
    }
};