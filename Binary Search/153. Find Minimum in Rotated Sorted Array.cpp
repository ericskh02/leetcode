class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mn = nums[0];
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[l]<=nums[m]){
                mn = min(mn,nums[l]);
                l = m + 1;
            } else {
                mn = min(mn,nums[m]);
                r = m - 1;
            }
        }
        return mn;
    }
};
