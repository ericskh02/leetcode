class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visited, int curr){
        if(visited[curr]==1) return false;
        if(visited[curr]==2) return true;
        visited[curr] = 1;
        for(int i = 0;i<graph[curr].size();i++){
            if(!dfs(graph,visited,graph[curr][i])) return false;
        }        
        visited[curr] = 2;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0); // 0 == not visited, 1 == visiting, 2 == visited
        vector<vector<int>> graph(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);    
        }
        for(int i = 0;i<numCourses;i++){
            if(visited[i]!=0) continue;
            if(!dfs(graph,visited,i)) return false;
        }
        return true;
    }
};
