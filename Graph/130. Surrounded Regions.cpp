class Solution {
public:
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]!='O'){
            return;
        }    
        board[x][y] = 'C';
        dfs(board,x+1,y);
        dfs(board,x-1,y);
        dfs(board,x,y+1);
        dfs(board,x,y-1);
    }
    void solve(vector<vector<char>>& board) {
        for(int i = 0;i<board.size();i++){
            dfs(board,i,0);
            dfs(board,i,board[0].size()-1);
        }
        for(int i = 0;i<board[0].size();i++){
            dfs(board,0,i);
            dfs(board,board.size()-1,i);
        }
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]!='C'){
                    board[i][j] = 'X';    
                }
            }
        }    
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]=='C'){
                    board[i][j] = 'O';    
                }
            }
        }
    }
};
