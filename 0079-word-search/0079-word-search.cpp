class Solution {
public:
    bool find(vector<vector<char>>& board, vector<vector<int>>& vis, string& word, int r, int c, int ind){
    if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || board[r][c] != word[ind] || vis[r][c]){
        return false;
    }
        if(ind == word.size()-1)return true;

        int dr[] = {-1,0,+1,0};
        int dc[] = {0,-1,0,+1};
        vis[r][c] = 1;
        for(int i=0; i<4; i++){
            int nr = r+dr[i];
            int nc = c+dc[i];        
            if(find(board,vis,word,nr,nc,ind+1))return true;           
        }
        vis[r][c] = 0;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0]){
                    if(find(board,vis,word,i,j,0))return true;
                }
                
            }
        }
        return false;
    }
};