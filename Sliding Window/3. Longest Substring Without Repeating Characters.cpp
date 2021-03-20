class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
        int l = 0;
        int ans = 1;
        unordered_map<char,int> mp;
        for(int r = 0;r<s.size();r++){
            if(mp.find(s[r])==mp.end() || mp[s[r]]<l){
                mp[s[r]] = r;
            } else {
                l = mp[s[r]] + 1;
                mp[s[r]] = r;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};
