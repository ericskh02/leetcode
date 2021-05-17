class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int ans = INT_MAX;
        int tempsum = 0;
        for(int r = 0;r<nums.size();r++){
            tempsum += nums[r];
            while(tempsum>=target){
                ans = min(ans,r-l+1);
                tempsum-=nums[l];
                l++;
            }
        }
        return (ans==INT_MAX) ? 0 : ans;
    }
};
