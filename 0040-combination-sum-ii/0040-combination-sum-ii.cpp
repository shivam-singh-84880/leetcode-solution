class Solution {
public:
    void find(int ind, vector<vector<int>>& ans, vector<int>& candidates,int t,vector<int> path,int& n){
        if(t == 0){
            ans.push_back(path);
            return;
        }
        
        for(int i=ind; i<n; i++){
            if(i > ind && candidates[i-1] == candidates[i])continue;
            if(t < candidates[i]) break;
            path.push_back(candidates[i]);
            find(i+1,ans,candidates,t-candidates[i],path,n);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();
        find(0,ans,candidates,target,path,n);
        return ans;
    }
};