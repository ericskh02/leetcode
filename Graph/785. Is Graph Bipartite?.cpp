class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& color,int parentColor,int curr){
        if(color[curr]==-1){
            color[curr] = !parentColor;
            for(int i = 0;i<graph[curr].size();i++){
                if(!dfs(graph,color,!parentColor,graph[curr][i])) return false;    
            }
            return true;
        } else if(color[curr] == parentColor){
            return false;
        }             
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i = 0;i<graph.size();i++){
            if(color[i]!=-1) continue;
            if(!dfs(graph,color,1,i)) return false;
        }
        return true;
    }
};
