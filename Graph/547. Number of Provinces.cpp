class Solution {
public:
    int findParent(int n, vector<int>& parent){
        if(parent[n]==n) return n;
        else {
            parent[n] = findParent(parent[n],parent);
            return parent[n];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = isConnected.size();
        vector<int> parent(isConnected.size(),0);
        for(int i = 0;i<isConnected.size();i++){
            parent[i] = i;
        }
        for(int i = 0;i<isConnected.size();i++){
            for(int j = 0;j<isConnected.size();j++){
                if(isConnected[i][j]==1){
                    int iParent = findParent(i,parent);
                    int jParent = findParent(j,parent);
                    if(iParent!=jParent){
                        parent[jParent] = iParent;
                        ans--;
                    }
                }
            }
        }
        return ans;
    }
};
