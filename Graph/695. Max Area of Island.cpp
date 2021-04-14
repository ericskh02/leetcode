class Solution {
public:
    int area(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=1){
            return 0;    
        }            
        grid[x][y] = 2;
        return 1 + area(grid,x+1,y) + area(grid,x-1,y) + area(grid,x,y+1) + area(grid,x,y-1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int mx = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    mx = max(mx,area(grid,i,j));    
                }
            }
        }            
        return mx;
    }
};
