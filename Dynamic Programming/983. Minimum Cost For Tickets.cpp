class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> minpay(days.back()+1);
        minpay[0] = 0;
        int i = 0;
        for(int day = 1;day<=days.back();day++){
            if(day<days[i]){
                minpay[day] = minpay[day-1];    
            } else {
                int temp = minpay[day-1]+costs[0];
                if(day>=7){
                    temp = min(temp,minpay[day-7]+costs[1]);
                } else {
                    temp = min(temp,costs[1]);
                }
                if(day>=30){
                    temp = min(temp,minpay[day-30]+costs[2]);
                } else {
                    temp = min(temp,costs[2]);
                }
                minpay[day] = temp;
                i++;
            }
        }
        return minpay.back();
    }
};
