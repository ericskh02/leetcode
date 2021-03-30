class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& candidates, int target, int sum, int i,vector<int>& combine){
        if(sum==target){
            ans.emplace_back(combine);
            return;
        }    
        if(i>=candidates.size()){
            return;
        }
        for(int j = i;j<candidates.size() && candidates[j]+sum<=target;j++){
            combine.push_back(candidates[j]);
            dfs(candidates,target,sum+candidates[j],j,combine);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());   
        vector<int> combine;
        dfs(candidates,target,0,0,combine);
        return ans;
    }
};
