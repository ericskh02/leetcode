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
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for(int i = 0;i<26;i++){
            parent[i] = i;
        }
        vector<string> notequal;
        for(int i = 0;i<equations.size();i++){
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            char operand = equations[i][1];
            if(operand=='='){
                int aParent = findParent(a,parent);
                int bParent = findParent(b,parent);
                if(aParent!=bParent){
                    parent[aParent] = bParent;    
                }
            } else {
                notequal.push_back(equations[i]);
            }
        }
        for(int i = 0;i<notequal.size();i++){
            int a = notequal[i][0] - 'a';
            int b = notequal[i][3] - 'a';
            if(findParent(a,parent)==findParent(b,parent)) return false;
        }
        return true;
    }
};
