class Solution {
public:
    vector<vector<int>> ans;
    void traversal(vector<int>& candidates, int target, int index, vector<int> combine){
        if(target==0){
            if(find(ans.begin(),ans.end(),combine)==ans.end()) ans.push_back(combine);
            return;
        }
        if(index==candidates.size()) return;
        traversal(candidates,target,index+1,combine);
        if(target-candidates[index]>=0){
            combine.push_back(candidates[index]);
            traversal(candidates,target-candidates[index],index,combine);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        traversal(candidates,target,0,temp);
        return ans;
    }
};
