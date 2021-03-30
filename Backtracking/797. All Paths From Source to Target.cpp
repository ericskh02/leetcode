class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<vector<int>>& graph, int curr, vector<int>& path){
        if(curr==graph.size()-1) ans.emplace_back(path);
        for(int i = 0;i<graph[curr].size();i++){
            path.push_back(graph[curr][i]);
            dfs(graph,graph[curr][i],path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(graph,0,path);
        return ans;
    }
};
