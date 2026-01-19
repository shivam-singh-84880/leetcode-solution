class Solution {
public:
    int n;
    int m;

    bool check(int side, vector<vector<int>>& pre, int &t) {
        int sum,r2,c2=0;
        for (int i = 0; i + side - 1 < n; i++) {
            for (int j = 0; j + side - 1 < m; j++) {
                r2 = i+side-1;
                c2 = j+side-1;
                sum = pre[r2][c2] - (i>0 ? pre[i - 1][c2]:0) - (j>0 ? pre[r2][j - 1]:0)
                 + (i>0 && j>0 ? pre[i - 1][j - 1]:0);
                if (sum <= t) {
                    return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> pre(n,vector<int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pre[i][j] = mat[i][j] + (i > 0 ? pre[i - 1][j] : 0) + 
                (j > 0 ? pre[i][j - 1] : 0) - (i > 0 && j > 0 ? pre[i - 1][j - 1] : 0);
            }
        }

        int s=1;
        int e=min(n,m);
        while(s <= e){
            int mid = (s+e)/2;
            if(check(mid,pre,threshold)){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return e;
    }
};