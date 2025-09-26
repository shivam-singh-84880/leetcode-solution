class Solution {
public:
    vector<vector<int>> ans;
    void find(int ind, int k, int t, vector<int> path){
        if(t == 0 && k == 0){
            ans.push_back(path);
            return;
        }
        for(int i=ind; i<=9; i++){
            if(t < i)break;
            path.push_back(i);
            find(i+1,k-1,t-i,path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        find(1,k,n,path);
        return ans;
    }
};