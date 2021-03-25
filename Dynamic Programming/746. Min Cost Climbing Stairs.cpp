class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()<2) return 0;
        vector<int> cheapest(cost.size()+1);
        cheapest[0] = cost[0];
        cheapest[1] = cost[1];
        for(int i = 2;i<cost.size();i++){
            cheapest[i] = min(cheapest[i-1],cheapest[i-2]) + cost[i];
        }
        return min(cheapest[cost.size()-1],cheapest[cost.size()-2]);
    }
};
