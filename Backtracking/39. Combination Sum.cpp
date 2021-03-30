class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int i, int sum, vector<int>& combine)     {
        if(target==sum){
            ans.push_back(combine);
            return;
        }
        if(i>=candidates.size()){
            return;
        }
        dfs(candidates,target,i+1,sum,combine);
        if(sum+candidates[i]<=target){
            combine.push_back(candidates[i]);
            dfs(candidates,target,i,sum+candidates[i],combine);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combine;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,0,combine);
        return ans;
    }
};
