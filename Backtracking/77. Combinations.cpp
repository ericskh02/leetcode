class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int n,int k,int i,vector<int>& combination){
        if(combination.size()==k){
            ans.emplace_back(combination);
            return;
        }    
        for(int j = i;j<=n;j++){
            combination.push_back(j);
            dfs(n,k,j+1,combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        dfs(n,k,1,combination);
        return ans;
    }
};
