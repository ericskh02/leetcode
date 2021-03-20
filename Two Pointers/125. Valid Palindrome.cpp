class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i = 0;i<s.size();i++){if(s[i]>='A' && s[i]<='Z'){
                temp += s[i]+('a'-'A');
            } else if(s[i]>='a' && s[i]<='z' || s[i]>='0' && s[i]<='9'){
                temp += s[i];
            }
        }
        s = temp;
        int l = 0;
        int r = s.size()-1;
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
