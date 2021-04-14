class Solution {
public:
    void dfs(vector<vector<int>>& rooms,vector<bool>& visited, int room){
        if(visited[room]) return;
        visited[room] = true;
        for(auto key : rooms[room]){
            dfs(rooms,visited,key);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(rooms,visited,0);
        bool allVisited = true;
        for(auto v:visited){
            if(!v) allVisited = false;
        }
        return allVisited;
    }
};
