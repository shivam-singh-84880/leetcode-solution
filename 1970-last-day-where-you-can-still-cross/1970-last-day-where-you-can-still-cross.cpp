class dsu{
    vector<int> par;
public :
    dsu(int n){
        par.resize(n);
        iota(par.begin(), par.end(),0);
    }

    int findPar(int node){
        if(par[node] == node) return node;
        return par[node] = findPar(par[node]);
    }

    void unite(int v, int u){
        int pv = findPar(v);
        int pu = findPar(u);

        if(pv == pu) return;
        
        par[pu] = pv;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int n = row*col + 2;
        int b = row*col+1;
        vector<vector<int>> grid(row, vector<int> (col,1));
        dsu d(n);
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=row*col-1; i>=0; i--){
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;
            grid[r][c] = 0;
            int id = r*col + c;

            for(int j=0; j<4; j++){
                int nr = r + dir[j][0];
                int nc = c + dir[j][1];

                if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 0){
                    d.unite(id,nr*col+nc);
                }

            }

            if(r == 0){
                d.unite(0,id);
            }

            if(r == row-1){
                d.unite(b,id);
            }

            if(d.findPar(0) == d.findPar(b)){
                return i;
            }
        }
        return -1;
    }
};