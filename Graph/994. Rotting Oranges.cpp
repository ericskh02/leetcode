class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }            
            }
        }
        int minute = 0;
        while(!q.empty()){
            minute++;
            int size = q.size();
            for(int i = 0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=1) continue;
                grid[x][y] = 2;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
        }
        bool allRotten = true;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1) allRotten = false;
            }
        }
        return (allRotten) ? ((minute) ? minute-1 : minute) : -1;
    }
};
