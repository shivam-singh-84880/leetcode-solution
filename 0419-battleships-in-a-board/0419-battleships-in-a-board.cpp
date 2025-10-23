class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board){
        if(r>=board.size() || c>=board[0].size() || board[r][c] == '.'){
            return;
        }
        board[r][c] = '.';
        dfs(r,c+1,board);
        dfs(r+1,c,board);
    }

    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'X'){
                    cnt++;
                    dfs(i,j,board);
                }
            }
        }
        return cnt;
    }
};