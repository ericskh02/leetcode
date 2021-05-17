class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l = 0;
        int r = l+p.size()-1;
        unordered_map<char,int> pmap;
        for(auto c:p){
            pmap[c]++;
        }
        vector<int> ans;
        unordered_map<char,int> mp;
        for(int i = l;i<r;i++){
            mp[s[i]]++;
        }
        while(r<s.size()){
            mp[s[r]]++;
            if(pmap == mp) ans.push_back(l);
            mp[s[l]]--;
            if(mp[s[l]]==0) mp.erase(s[l]);
            l++;
            r++;
        }
        return ans;
    }
};
