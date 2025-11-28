class Solution {
public:
    int dfs(int node, int par, vector<vector<int>>& adj, vector<int>& values, int& nc, int k){
        int sum=0;

        for(auto& nbr : adj[node]){
            if(nbr != par){
                sum += dfs(nbr,node, adj, values, nc, k);
            }
        }
        sum %= k;
        sum += values[node];
        sum %= k;
        if(sum == 0)nc++;

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for(auto& it : edges){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        int nc=0;
        dfs(0,-1,adj,values,nc,k);
        return nc;
    }
};