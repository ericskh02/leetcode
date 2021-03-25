class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0;i<matrix.size();i++){
            vector<int> curr = matrix[i];
            int mn = curr[0];
            int mx = curr[curr.size()-1];
            if(target>=mn && target<=mx){
                int l = 0;
                int r = curr.size()-1;
                while(l<=r){
                    int m = l + (r-l)/2;
                    if(curr[m]==target){
                        return true;
                    }
                    if (curr[m] > target){
                        r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }
            }
        }
        return false;
    }
};
