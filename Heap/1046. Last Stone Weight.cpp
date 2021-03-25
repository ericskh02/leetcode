class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(stones.begin(),stones.end());
        while(q.size()>1){
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();
            if(stone1!=stone2){
                q.push(stone1-stone2);
            }
        }
        return (q.empty()) ? 0 : q.top();
    }
};
