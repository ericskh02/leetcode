class Solution {
public:
    int ans = 0;
    void dfs(int n,vector<vector<bool>>& chessboard,int chesscount,int x){
        if(chesscount==n) {
            ans++;
            return;
        }
        for(int i = 0;i<n;i++){
            bool canPlace = true;
            for(int j = 0;j<n;j++){
                if(chessboard[j][i]){
                    canPlace = false;
                    break;
                }
            }        
            if(!canPlace){
                continue;
            }
            int tempX = x;
            int tempY = i;
            while(tempX>0 && tempY>0){
                tempX--;
                tempY--;
            }
            while(tempX<n && tempY<n){
                if(chessboard[tempX][tempY]){
                    canPlace = false;
                    break;
                }
                tempX++;
                tempY++;
            }
            if(!canPlace){
                continue;
            }
            tempX = x;
            tempY = i;
            while(tempX>0 && tempY<n-1){
                tempX--;
                tempY++;
            }
            while(tempX<n && tempY>=0){
                if(chessboard[tempX][tempY]){
                    canPlace = false;
                    break;
                }
                tempX++;
                tempY--;
            }
            if(!canPlace){
                continue;
            }
            chessboard[x][i] = true;
            dfs(n,chessboard,chesscount+1,x+1);
            chessboard[x][i] = false;
        }                                
    }
    int totalNQueens(int n) {
        vector<vector<bool>> chessboard(n,vector<bool>(n,false));
        dfs(n,chessboard,0,0);
        return ans;  
    }
};
