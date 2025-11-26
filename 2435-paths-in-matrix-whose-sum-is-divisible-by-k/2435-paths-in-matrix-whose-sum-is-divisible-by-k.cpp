class Solution {
public:
    int mod = 1e9+7;
    int find(vector<vector<int>>& grid, int& k, int sum, int r, int c, int& n, int& m){
        if(r>=n || c>=m) return 0;

        sum = (sum + grid[r][c])%k;
        if(r == n-1 && c == m-1){
            if(sum%k == 0)return 1;
            else return 0;
        }

        int right = find(grid,k,sum,r,c+1,n,m);
        int left = find(grid,k,sum,r+1,c,n,m);

        return (left+right)%mod;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        //vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k,0)));
        vector<vector<int>> curr(m+1, vector<int>(k,0));
        vector<vector<int>> next(m+1, vector<int>(k,0));
        for(int r=n-1; r>=0; r--){
            for(int c=m-1; c>=0; c--){
                for(int sum=0; sum<k; sum++){
                    int newsum = (sum + grid[r][c])%k;
                    if(r == n-1 && c == m-1){
                        if(newsum%k == 0){
                            curr[c][sum] = 1;
                            continue;
                        }
                    }

                    int right = curr[c+1][newsum];
                    int left = next[c][newsum];

                    curr[c][sum] =  (left+right)%mod;
                }
                next = curr;
            }
        }
        //return find(grid,k,0,0,0,n,m);
        return curr[0][0];
    }
};