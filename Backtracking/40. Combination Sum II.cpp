class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int index, vector<int>& combine){
        if(target==0){
            if(find(ans.begin(),ans.end(),combine)==ans.end()){
                ans.emplace_back(combine);
            }
            return;
        }
        if(index==candidates.size()) return;
        dfs(candidates, target, index+1, combine);
        if(target-candidates[index]>=0){
            combine.push_back(candidates[index]);
            dfs(candidates, target-candidates[index], index+1, combine);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> newV;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,newV);
        return ans;
    }
};
