class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            vector<int> curr = grid[i];
            int l = 0;
            int r = curr.size()-1;
            while(l<=r){
                int m = l + (r-l)/2;
                if(curr[m]>=0){
                    l = m+1;
                } else {
                    r = m-1;
                }
            }
            if(l<curr.size()){
                ans += curr.size()-l;
            }
        }
        return ans;
    }
};
