class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int> dif;
        for(int i = 1;i<heights.size();i++){
            int tempdif = heights[i]-heights[i-1];
            if(tempdif>0){
                dif.push_back(tempdif);    
            } else {
                dif.push_back(0);
            }         
        }    
        long long int sum = 0;
        int ans = 0;
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i = 0;i<dif.size();i++){
            if(pq.size()<ladders) {
                pq.push(dif[i]);
            }
            else if(!pq.empty() && dif[i] > pq.top()){
                sum += pq.top();
                pq.pop();
                pq.push(dif[i]);
            } else {
                sum += dif[i];
            }
            if(sum<=bricks) ans++;
            else break;
        }
        return ans;
    }
};
