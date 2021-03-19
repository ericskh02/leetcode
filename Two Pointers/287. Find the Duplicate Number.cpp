class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<2){
            return nums[0];
        }
        int fast = nums[0];
        int slow = nums[0];
        int x = -1;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while(fast!=slow);
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
