class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0] = 1;

        int dr[] = {-1,0,0,1};
        int dc[] = {0,-1,1,0};
        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if(row == n-1 && col == n-1)return dist;
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                     pq.push({max(dist,grid[nr][nc]),{nr,nc}});
                }
            }
        }
        return 0;
    }
};