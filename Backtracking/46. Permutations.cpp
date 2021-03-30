class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums,vector<int>& permutation){
        if(nums.empty()) {
            ans.emplace_back(permutation);
            return;
        }        
        for(int i = 0;i<nums.size();i++){
            int temp = nums[i];
            permutation.push_back(temp);
            nums.erase(nums.begin()+i);
            dfs(nums,permutation);
            permutation.pop_back();
            nums.insert(nums.begin()+i,temp);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        dfs(nums,permutation);
        return ans;
    }
};
