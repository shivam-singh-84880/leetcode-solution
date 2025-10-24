class Solution {
public:

    int dx[4] = {0, 0, -1, 1 };
    int dy[4] = {-1, 1, 0, 0};

    void calculateMinFireTime(vector<vector<int>>& minFireTime, vector<vector<int>>& grid, int& n, int& m, int& currTime){
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){    
                    visited[i][j] = true;
                    minFireTime[i][j] = currTime;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()){
            currTime++;
            int size = q.size();
            for(int i=0; i<size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || (grid[nx][ny] == 2) || visited[nx][ny])
                        continue;
                    minFireTime[nx][ny] = currTime;    
                    visited[nx][ny] = true;                        
                    q.push({nx, ny});               
                }
            }
        }
    }

    bool isPossible(int t, vector<vector<int>>& minFireTime, vector<vector<int>>& grid, int& n, int& m) {
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        queue<pair<int, int>> q;
        int currTime = t;      
        if (minFireTime[0][0] <= currTime)
            return false;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()){
            currTime++;
            int size = q.size();
            for(int i=0; i<size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || (grid[nx][ny] == 2) || visited[nx][ny])
                        continue;
                    if(nx == n-1 && ny == m-1 && currTime <= minFireTime[n-1][m-1])
                        return true; 
                    if(currTime < minFireTime[nx][ny]){
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;           
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int timer = 0;
        vector<vector<int>> minFireTime(n,vector<int>(m,INT_MAX));
        calculateMinFireTime(minFireTime,grid,n,m,timer);

        int mst = 0;
        int met = timer;
        int ans = -1;

        while(mst <= met){
            int mid = (mst+met)/2;
            if(isPossible(mid,minFireTime,grid,n,m)){
                mst = mid+1;
                ans = mid;
            }
            else met = mid-1;
        }

        if(ans == timer) return 1e9;
        else return ans;
    }
};

