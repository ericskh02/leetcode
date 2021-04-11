class Solution {
public:
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int x, int y, int pre){
        if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]<=pre) return 0;
        if(dp[x][y]>0) return dp[x][y];
        dp[x][y] = max(dp[x][y],dfs(matrix,dp,x+1,y,matrix[x][y])+1);
        dp[x][y] = max(dp[x][y],dfs(matrix,dp,x-1,y,matrix[x][y])+1);
        dp[x][y] = max(dp[x][y],dfs(matrix,dp,x,y+1,matrix[x][y])+1);
        dp[x][y] = max(dp[x][y],dfs(matrix,dp,x,y-1,matrix[x][y])+1);
        return dp[x][y];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),0));
        int mx = 1;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                mx = max(mx,dfs(matrix,dp,i,j,-1));
            }
        }   
        return mx;
    }
};
