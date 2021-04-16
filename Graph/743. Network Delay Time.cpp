class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n+1,vector<int>(n+1,INT_MAX));
        vector<bool> visited(n+1,false);
        vector<int> distancefromk(n+1,INT_MAX);
        for(int i = 0;i<times.size();i++){
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        graph[k][k] = 0;
        distancefromk[k] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int curr = pq.top().second;
            pq.pop();
            if(visited[curr]) continue;
            visited[curr] = true;
            for(int i = 1;i<=n;i++){
                if(graph[curr][i]!=INT_MAX){
                    distancefromk[i] = min(distancefromk[i],distancefromk[curr]+graph[curr][i]);
                    pq.push({distancefromk[i],i});
                }
            }                    
        }
        int mx = INT_MIN;
        for(int i = 1;i<=n;i++){
            mx = max(mx,distancefromk[i]);
        }
        return (mx==INT_MAX) ? -1 : mx; 
    }
};
