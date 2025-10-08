class Solution {
public:
    vector<vector<string>> ans;

    void find(int col, int n, vector<string>& temp,vector<bool>& left, vector<bool>& up, vector<bool> & down){
        if(col == n){
            ans.push_back(temp);
            return;
        }
        for(int row=0; row<n; row++){
            if(left[row]==false && up[n-1 + col - row]==false && down[row+col]==false){
                temp[row][col] = 'Q';
                left[row] = true;
                up[n-1+col-row] = true;
                down[row+col] = true;

                find(col+1,n,temp,left,up,down);

                temp[row][col] = '.';
                left[row] = false;
                up[n-1+col-row] = false;
                down[row+col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n);
        vector<bool> left(n,false);
        vector<bool> up(2*n-1,false);
        vector<bool> down(2*n-1,false);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            temp[i] = s;
        }
        find(0,n,temp,left,up,down);
        return ans;
    }
};