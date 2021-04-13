class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& child, vector<int>& informTime, int employee, int time){
        ans = max(ans,time);
        time += informTime[employee];
        for(int i = 0;i<child[employee].size();i++){
            dfs(child,informTime,child[employee][i], time);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<vector<int>> child(n);
    for(int i = 0;i<n;i++){
        vector<int> temp;
        child[i] = temp;
    }
    for(int i = 0;i<n;i++){
        if(manager[i]!=-1) child[manager[i]].push_back(i); 
    }    
    dfs(child, informTime, headID,0);
    return ans;
    }
};
