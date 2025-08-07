class dsu{
public:
    vector<int> parent;
    vector<int> size;
    dsu(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int fndpar(int node){
        if(parent[node] == node)return node;
        return parent[node] = fndpar(parent[node]);
    }

    void unions(int v, int u){
        int rpu = fndpar(u);
        int rpv = fndpar(v);

        if(rpv == rpu) return;

        if(size[rpu] < size[rpv]){
            parent[rpu] = rpv;
            size[rpv] += size[rpu];
        }
        else{
            parent[rpv] = rpu;
            size[rpu] += size[rpv];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int sz = n*n;
        dsu ds(sz);

        int dr[] = {-1,0,0,+1};
        int dc[] = {0,-1,+1,0};
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int k=0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                            int node1 = i*n + j;
                            int node2 = nr*n + nc;
                            ds.unions(node1,node2);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    for(int k=0; k<4; k++){
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                            int node2 = nr*n + nc;
                            st.insert(ds.fndpar(node2));  
                        }
                    }
                    int maxi = 0;
                    for(auto val : st){
                        maxi += ds.size[val];
                    }
                    ans = max(ans,maxi+1);
                }
            }
        }

        if(!ans) return n*n;
        else return ans;
    }
};