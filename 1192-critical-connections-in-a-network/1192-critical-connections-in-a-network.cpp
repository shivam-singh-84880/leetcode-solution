class Solution {
public:
    void dfs(int node, int par, int dt, vector<int>& sdt, vector<int>& vis, vector<vector<int>>& adj, vector<vector<int>>& ans){
        vis[node] = 1;
        sdt[node] = dt;
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr,node,dt+1,sdt,vis,adj,ans);
                sdt[node] = min(sdt[node],sdt[nbr]);
                if(dt < sdt[nbr]){
                    ans.push_back({node,nbr});
                }
            }
            else if(par != nbr){
                sdt[node] = min(sdt[nbr],sdt[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> ans;
        vector<int> vis(n,0);
        vector<int> sdt(n);
        dfs(0,-1,0,sdt,vis,adj,ans);
        return ans;
    }
};