class Solution {
public:
    void find(int ind, int& n, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp){
        if(ind >= n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        find(ind+1,n,nums,ans,temp);
        temp.pop_back();
        find(ind+1,n,nums,ans,temp);
        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        find(0,n,nums,ans,temp);
        return ans;



        // vector<vector<int>> ans;
        // for(int i=0; i<pow(2,nums.size()); i++){
        //     vector<int> res;
        //     for(int j=0; j<nums.size(); j++){
        //         if(i&(1<<j)){
        //             res.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(res);
        // }
        // return ans;
    }
};