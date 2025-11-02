class Solution {
public:
    void markvis(int r, int c, vector<vector<int>>& grid, int& n, int& m){
        for(int nc=c+1; nc<n; nc++){
            if(grid[r][nc] == 2 || grid[r][nc] == 3)break;
            grid[r][nc] = 1;
        }
        for(int nc=c-1; nc>=0; nc--){
            if(grid[r][nc] == 2 || grid[r][nc] == 3)break;
            grid[r][nc] = 1;
        }
        for(int nr=r+1; nr<m; nr++){
            if(grid[nr][c] == 2 || grid[nr][c] == 3)break;
            grid[nr][c] = 1;
        }
        for(int nr=r-1; nr>=0; nr--){
            if(grid[nr][c] == 2 || grid[nr][c] == 3)break;
            grid[nr][c] = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        for(auto it : guards){
            grid[it[0]][it[1]] = 2;
        }
        for(auto it : walls){
            grid[it[0]][it[1]] = 3;
        }

        for(auto it : guards){
            markvis(it[0],it[1],grid,n,m);
        }

        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};