class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto n:nums){
            sum += n;
        }
        if(sum%2==1) return false;
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum+1,false));
        dp[0][0] = true;
        int target = sum/2;
        for(int i = 0;i<nums.size();i++){
            dp[i][nums[i]] = true;
            if(i==0){
                continue;
            }
            if(target-nums[i]>=0 && dp[i-1][target-nums[i]]){
                return true;
            }
            for(int j = 1;j<=sum;j++){
                if(dp[i-1][j]){
                    dp[i][j] = true;
                    dp[i][j+nums[i]] = true;
                }
            }
        }
        return false;
    }
};
