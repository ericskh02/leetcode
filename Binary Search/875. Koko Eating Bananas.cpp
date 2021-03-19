class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int mx = piles[piles.size()-1];
        int l = 1;
        int r = mx;
        while(l<=r){
            int m = l + (r-l)/2;
            int temp = 0;
            for(int i = 0;i<piles.size();i++){
                if(m>=piles[i]){
                    temp++;
                }
                else {
                    temp += (piles[i]%m==0)? piles[i]/m : piles[i]/m + 1;
                }
            }
            if(temp<=h){
                r = m-1;    
            } else {
                l = m+1;
            }
        }
        return l;
    }
};
