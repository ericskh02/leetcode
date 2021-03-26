class Solution {
public:
    int climbStairs(int n) {
        if(n<2) return n;
        int x = 1;
        int y = 1;
        for(int i = 2;i<=n;i++){
            int temp = y;
            y+=x;
            x = temp;
        }
        return y;
    }
};
