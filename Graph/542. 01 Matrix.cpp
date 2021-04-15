class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]!=0) matrix[i][j] = 10001;
            }
        }    
        queue<pair<int,int>> q;
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j+1});
                    q.push({i,j-1});
                }
            }
        }
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            step++;
            for(int i = 0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x<0 || x>=matrix.size() || y<0 || y>=matrix[0].size() || matrix[x][y]<10001){
                    continue;
                }
                matrix[x][y] = step;
                q.push({x+1,y});
                q.push({x-1,y});
                q.push({x,y+1});
                q.push({x,y-1});
            }
        }
        return matrix;
    }
};
