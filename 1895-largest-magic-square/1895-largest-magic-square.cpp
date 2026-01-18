class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> rowsum(n, vector<int>(m));
        vector<vector<int>> colsum(n,vector<int>(m));

        for (int i = 0; i < n; ++i) {
            rowsum[i][0] = grid[i][0];
            for (int j = 1; j < m; ++j) {
                rowsum[i][j] = rowsum[i][j - 1] + grid[i][j];
            }
        }

        for (int j = 0; j < m; ++j) {
            colsum[0][j] = grid[0][j];
            for (int i = 1; i < n; ++i) {
                colsum[i][j] = colsum[i - 1][j] + grid[i][j];
            }
        }



        for (int s = min(n, m); s >= 2; s--) {
            for (int i = 0; i + s - 1 < n; ++i) {
                for (int j = 0; j + s - 1 < m; ++j) {
                    int t = rowsum[i][j + s - 1] - (j > 0 ? rowsum[i][j - 1] : 0);
                    bool flag = false;
                    for (int r = i + 1; r < i + s; ++r) {
                        int sum = rowsum[r][j + s - 1] - (j > 0 ? rowsum[r][j - 1] : 0);
                        if (sum != t) {
                            flag = true;
                            break;
                        }
                    }


                    if(flag){
                        continue;
                    }

                    for(int c=j; c < j+s; c++){
                        int sum = colsum[i+s-1][c] - (i > 0 ? colsum[i-1][c] : 0);
                        if(sum != t){
                            flag = true;
                            break;
                        }
                    }

                    if(flag){
                        continue;
                    }

                    int d = 0;
                    int ad = 0;
                    for (int k = 0; k < s; ++k) {
                        d += grid[i + k][j + k];
                        ad += grid[i + k][j + s - 1 - k];
                    }

                    if (d == t && ad == t) {
                        return s;
                    }
                }
            }
        }
        return 1;
    }
};