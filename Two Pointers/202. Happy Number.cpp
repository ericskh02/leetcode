class Solution {
public:
    int happy(int n){
        int result = 0;
        while(n>0){
            result += (n%10)*(n%10);
            n/=10;
        }
        return result;
    }
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        do {
            fast = happy(happy(fast));
            slow = happy(slow);
        } while(fast!=slow && fast != 1);
        return (fast==1) ? true : false;
    }
};
