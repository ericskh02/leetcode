class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int& k, int& n,int sum, int i, vector<int>& combination){
        if(sum==n && combination.size()==k){
            ans.emplace_back(combination);
            return;
        }
        if(combination.size()>=k) return;
        for(int j = i;j+sum<=n && j<=9;j++){
            combination.push_back(j);
            dfs(k,n,sum+j,j+1,combination);
            combination.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        dfs(k,n,0,1,combination);
        return ans;
    }
};
