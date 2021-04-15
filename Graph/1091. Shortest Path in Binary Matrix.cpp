class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        if(grid[0][0]==1 || grid[grid.size()-1][grid[0].size()-1]==1) return -1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},1});
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int x = q.front().first.first;
                int y = q.front().first.second;
                int distance = q.front().second;
                q.pop();
                if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]!=0) continue;
                if(x==grid.size()-1 && y==grid[0].size()-1) ans = min(ans,distance);
                grid[x][y] = 2;
                distance++;
                q.push({{x+1,y},distance});
                q.push({{x-1,y},distance});
                q.push({{x,y+1},distance});
                q.push({{x,y-1},distance});
                q.push({{x+1,y+1},distance});
                q.push({{x-1,y+1},distance});
                q.push({{x+1,y-1},distance});
                q.push({{x-1,y-1},distance});
            }
        }
        return (ans==INT_MAX) ? -1 : ans;
    }
};
