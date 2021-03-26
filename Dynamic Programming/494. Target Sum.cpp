class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S<-1000 || S>1000) return 0;
        if(nums.size()==0) return 0;
        vector<vector<int>> dp(nums.size()+1,vector<int>(2000+1,0));
        dp[0][1000+nums[0]] = 1;
        dp[0][1000-nums[0]] += 1;
        for(int i = 1;i<nums.size();i++){
            for(int j = 0;j<=2000;j++){
                if(dp[i-1][j]>0){
                    dp[i][j+nums[i]] += dp[i-1][j];
                    dp[i][j-nums[i]] += dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][S+1000];
    }
};
