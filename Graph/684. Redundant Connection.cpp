class Solution {
public:
    int findParent(int n, vector<int>& parent){
        if(parent[n]==n){
            return n;
        } else {
            parent[n] = findParent(parent[n],parent);
            return parent[n];
        }    
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent;
        vector<int> ans(2,0);
        for(int i = 0;i<=edges.size();i++){
            parent.push_back(i);
        }
        for(int i = 0;i<edges.size();i++){
            int x = findParent(edges[i][0],parent);
            int y = findParent(edges[i][1],parent);
            if(x!=y){
                parent[x] = y;    
            } else {
                ans[0] = edges[i][0];
                ans[1] = edges[i][1];
            }
        }
        return ans;
    }
};
