class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i = 0;i<(1<<nums.size());i++){
            vector<int> temp;
            for(int j = 0;j<nums.size();j++){
                if((i>>j)&1){
                    temp.emplace_back(nums[j]);        
                }
            }
            ans.emplace_back(temp);
        }    
        return ans;
    }
};
