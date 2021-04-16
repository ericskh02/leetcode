class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>& visit, vector<int>& ans, int& idx, int curr){
        if(visit[curr]==1) return false;
        if(visit[curr]==2) return true;
        visit[curr] = 1;
        for(int i = 0;i<graph[curr].size();i++){
            if(!dfs(graph,visit,ans,idx,graph[curr][i])) return false;
        }
        visit[curr] = 2;
        ans[idx] = curr;
        idx--;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> visit(numCourses,0);
        vector<int> ans(numCourses,0);
        int idx = numCourses-1;
        for(auto p: prerequisites){
            graph[p[1]].push_back(p[0]);    
        }
        for(int i = 0;i<numCourses;i++){
            if(visit[i]!=0) continue;
            if(!dfs(graph,visit,ans,idx,i)){
                ans.resize(0);
                return ans;
            }
        }
        return ans;
    }
};
