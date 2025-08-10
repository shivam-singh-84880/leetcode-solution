class Solution {
public:
    int find(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(row < 0 || col < 0)return 1e9;
        if(row == 0 && col == 0)return grid[0][0];
        if(dp[row][col] != -1)return dp[row][col];
        int s1 = grid[row][col] + find(row-1,col,grid,dp);
        int s2 = grid[row][col] + find(row,col-1,grid,dp);
        return dp[row][col] = min(s1,s2);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        vector<int> curr(m,0);
        curr[0] = grid[0][0];
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(row==0 && col==0)continue;
                int s1 = 1e9;
                if(row>0) s1 = grid[row][col] + curr[col];
                
                int s2 = 1e9;
                if(col>0) s2 = grid[row][col] + curr[col-1];
                
                curr[col] = min(s1,s2);
            }
        }
        return curr[m-1];
        //return find(n-1,m-1,grid,dp);
    }
};

/* 
int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        dist[0][0] = grid[0][0];

        int dr[] = {0,1};
        int dc[] = {1,0};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int dt = it.first;
            int row = it.second.first;
            int col = it.second.second;
            if(row == n-1 && col == m-1) return dt;
            for(int i=0; i<2; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    if(dt + grid[nr][nc] < dist[nr][nc]){
                        dist[nr][nc] = dt + grid[nr][nc];
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }

*/