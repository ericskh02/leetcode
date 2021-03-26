class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i = 1;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                int temp = matrix[i-1][j];
                if(j>0){
                    temp = min(temp,matrix[i-1][j-1]);
                }
                if(j<matrix[0].size()-1){
                    temp = min(temp,matrix[i-1][j+1]);
                }
                matrix[i][j] += temp;
            }
        }
        
        int mn = INT_MAX;
        for(int i = 0;i<matrix[0].size();i++){
            mn = min(mn,matrix[matrix.size()-1][i]);
        }
        return mn;
    }
};
