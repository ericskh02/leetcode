class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][1] = -prices[0];
        for(int i = 1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+prices[i]);
            if(i-2>=0){
                dp[i][1] = max(dp[i-2][0]-prices[i],dp[i-1][1]);
            } else {
                dp[i][1] = max(-prices[i],dp[i-1][1]);
            }
            
        }
        return dp[prices.size()-1][0];
    }
};
