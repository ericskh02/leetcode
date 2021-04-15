class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        vector<int> color(N+1,-1);
        for(int i = 0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        queue<pair<int,int>> q;
        for(int i = 0;i<N;i++){
            if(color[i]!=-1) continue;
            q.push({i,0});
            while(!q.empty()){
                int size = q.size();
                for(int i = 0;i<size;i++){
                    int curr = q.front().first;
                    int tempcolor = q.front().second; 
                    q.pop();
                    if(color[curr]!=-1 && color[curr]!=tempcolor) return false;
                    if(color[curr]!=-1) continue;
                    color[curr] = tempcolor;
                    tempcolor = !tempcolor;
                    for(int j = 0;j<graph[curr].size();j++){
                        q.push({graph[curr][j],tempcolor});    
                    }
                }    
            }
        }

        return true;
    }
};
