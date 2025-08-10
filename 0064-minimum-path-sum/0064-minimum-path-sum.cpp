class Solution {
public:
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
};