class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr,adj,vis);
            }
        }
    }

    bool valid(string s1, string s2){
        int cnt=0;
        for(int i=0; i<s1.size(); i++){
            if(s1[i] != s2[i]){
                cnt++;
                if(cnt > 2){
                    return false;
                }
            }
        }
        return (cnt == 2);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((strs[i] == strs[j]) || (strs[i].size() == strs[j].size() && valid(strs[i],strs[j]))){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }
        return cnt;
    }
};