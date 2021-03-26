class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1,vector<int>(target+1,0));
        dp[0][0] = 0;
        for(int i = 1;i<=min(target,f);i++){
            dp[1][i] = 1;
        }
        for(int i = 1;i<=d;i++){
            for(int j = i;j<=min(target,i*f);j++){
                for(int k = 1;k<=f;k++){
                    if(j-k>0){
                        dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % 1000000007;
                    }
                }
            }
        }
        return dp[d][target];
    }
};
