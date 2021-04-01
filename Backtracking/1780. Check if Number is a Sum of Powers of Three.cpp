class Solution {
public:
    bool dfs(int n,vector<int>& powerofthree,int index){
        if(n==0) return true;
        for(int i = index;i<powerofthree.size() && n-powerofthree[i]>=0;i++){
            if (dfs(n-powerofthree[i],powerofthree,i+1)) return true;    
        }
        return false;
    }
    bool checkPowersOfThree(int n) {
        vector<int> powerofthree;
        for(int i = 0;pow(3,i)<=n && pow(3,i)<=10000001;i++){
            powerofthree.push_back(pow(3,i));    
        }
        return dfs(n,powerofthree,0);
    }
};
