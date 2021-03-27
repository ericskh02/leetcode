class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int l = 0;
        for(int i = 0;i<s.size();i++){
            (s[i]=='L')?l++:l--;
            if(!l){
                ans++;
            }
        }
        return ans;
    }
};
