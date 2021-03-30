class Solution {
public:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, vector<int>& permutation){
        if(nums.empty()){
            ans.emplace_back(permutation);
        }    
        for(int i = 0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int temp = nums[i];
            permutation.push_back(temp);
            nums.erase(nums.begin()+i);
            dfs(nums,permutation);
            permutation.pop_back();
            nums.insert(nums.begin()+i,temp);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> permutation;
        dfs(nums,permutation);
        return ans;
    }
};
