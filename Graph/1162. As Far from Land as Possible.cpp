class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        bool noland = true;
        bool nowater = true;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    noland = false;
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                } else {
                    nowater = false;
                }
            }
        }    
        int step = 0;
        while(!q.empty()){
            step++;
            int size = q.size();
            for(int i = 0;i<size;i++){
                pair<int,int> p = q.front();
                q.pop();
                if(p.first<0 || p.first>=grid.size() || p.second<0 || p.second>=grid[0].size() || grid[p.first][p.second]!=0){
                    continue;
                }
                grid[p.first][p.second] = 2;
                q.push({p.first+1,p.second});
                q.push({p.first-1,p.second});
                q.push({p.first,p.second+1});
                q.push({p.first,p.second-1});
            }
        }
        return (noland || nowater) ? -1 : step-1;
    }
};
