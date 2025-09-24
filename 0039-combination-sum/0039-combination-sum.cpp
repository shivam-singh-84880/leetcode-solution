class Solution {
public:
    void find(int ind, vector<vector<int>>& ans, vector<int>& candidates,int t,vector<int> path,int& n){
        if(ind >= n)return;
        if(t == 0){
            ans.push_back(path);
            return;
        }
        if(t >= candidates[ind]){
            path.push_back(candidates[ind]);
            find(ind,ans,candidates,t-candidates[ind],path,n);
            path.pop_back();
        }
        find(ind+1,ans,candidates,t,path,n);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        find(0,ans,candidates,target,path,n);
        return ans;
    }
};