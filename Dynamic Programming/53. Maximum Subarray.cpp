class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = nums[0];
        int temp = 0;
        for(auto val:nums){
            temp = max(temp,0)+val;
            mx = max(mx,temp);
        }
        return mx;
    }
};
