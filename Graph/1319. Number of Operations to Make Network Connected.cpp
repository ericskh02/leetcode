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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int count = n;
        int redundant = 0;
        vector<int> parent(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(auto c: connections){
            int x = findParent(c[0],parent);
            int y = findParent(c[1],parent);
            if(x!=y){
                parent[x] = y;
                count--;
            } else {
                redundant++;
            }
        }
        
        return (redundant>=count-1) ? count-1 : -1;
    }
};
