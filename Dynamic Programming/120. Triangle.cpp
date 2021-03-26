class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1;i<triangle.size();i++){
            for(int j = 0;j<triangle[i].size();j++){
                int temp = INT_MAX;
                if(j-1>=0){
                    temp = min(temp,triangle[i-1][j-1]);
                }
                if(j<triangle[i-1].size()){
                    temp = min(temp,triangle[i-1][j]);
                }
                triangle[i][j] += temp;
            }
        }
        int mn = INT_MAX;
        for(int i = 0;i<triangle.back().size();i++){
            mn = min(mn,triangle.back()[i]);
        }
        return mn;
    }
};
