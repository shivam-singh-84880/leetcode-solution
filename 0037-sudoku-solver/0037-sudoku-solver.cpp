class Solution {
public:
    bool valid(int r, int c, char ch, vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(board[i][c] == ch)return false;
            if(board[r][i] == ch)return false;
            if(board[3*(r/3) + i/3][3*(c/3) + i%3] == ch)return false;
        }
        return true;
    }

    bool solve(int row, int col,vector<vector<char>>& board){
        for(int i=row; i<9; i++){
            for(int j=(i==row?col:0); j<9; j++){
                if(board[i][j] == '.'){
                    for(char ch='1'; ch<='9'; ch++){
                        if(valid(i,j,ch,board)){
                            board[i][j] = ch;
                            if(solve(i,j+1,board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(0,0,board);
    }
};