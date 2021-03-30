class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int sum, int i, vector<int>& combine){
        if(sum==target){
            ans.emplace_back(combine);
            return;
        }
        for(int j = i;j<candidates.size() && sum+candidates[j]<=target;j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
            combine.push_back(candidates[j]);
            dfs(candidates,target,sum+candidates[j],j+1,combine);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> combine;
        dfs(candidates,target,0,0,combine);
        return ans;
    }
};
