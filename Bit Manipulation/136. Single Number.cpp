class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(auto n: nums){
            temp^=n;
        }
        return temp;
    }
};
