class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,int index,vector<int>& subset){
        ans.emplace_back(subset);
        for(int i = index;i<nums.size();i++){
            if(i>index && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            dfs(nums,i+1,subset);
            subset.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        dfs(nums,0,subset);
        return ans;
    }
};
