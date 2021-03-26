class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1;i<sqrt(n)+1;i++){
            squares.push_back(i*i);
        }
        vector<int> dp(n+1,pow(10,4)+1);
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            for(auto square:squares){
                if(square<=i){
                    dp[i] = min(dp[i],dp[i-square]+1);    
                }
            }    
        }
        return dp[n];
    }
};
