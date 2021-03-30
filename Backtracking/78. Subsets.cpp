class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int index, vector<int>& subset){
        ans.emplace_back(subset);
        for(int i = index;i<nums.size();i++){
            subset.push_back(nums[i]);
            dfs(nums,i+1,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        dfs(nums,0,subset);
        return ans;
    }
};
