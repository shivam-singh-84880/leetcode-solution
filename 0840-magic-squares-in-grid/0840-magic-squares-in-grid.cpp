class Solution {
public:
    int check(vector<vector<int>>& grid, int r, int c){
        unordered_set<int> st;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int num = grid[r+i][c+j];
                if(num < 0 || num > 9 || st.count(num)) return 0;
                else st.insert(num);
            }
        }

        for(int i=0; i<3; i++){
            int sumr = grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2];
            if(sumr != 15)return 0;
            int sumc = grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i];
            if(sumc != 15)return 0;
        }

        int dsum = grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2];
        int rdsum = grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c];

        if(dsum != 15 || rdsum != 15)return 0;

        return 1;

    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int res=0;
        for(int i=0; i<=nr-3; i++){
            for(int j=0; j<=nc-3; j++){
                res += check(grid,i,j);
            }
        }
        return res;
    }
};