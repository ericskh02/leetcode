class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num;
        while(l<=r){
            long long int mid = l + (r-l)/2;
            long long int temp = mid*mid;
            if(temp==num) return true;
            if(temp<num) l = mid+1;
            if(temp>num) r = mid-1;
        }
        return false;
    }
};
