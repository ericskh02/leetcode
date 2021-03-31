class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s){
        if(s.size()==0) return false;
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void dfs(string& s, int i, vector<string>& partition){
        if(i==s.size()) ans.emplace_back(partition);
        string temp = "";
        for(int j = i;j<s.size();j++){
            temp += s[j];
            if(isPalindrome(temp)){
                partition.push_back(temp);
                dfs(s,j+1,partition);
                partition.pop_back();
            }
        }         
    }
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        dfs(s,0,partition);
        return ans;
    }
};
