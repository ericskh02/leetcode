class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y, int scolor, int newColor){
        if(x<0 || x>=image.size() || y<0 || y>=image[0].size() || image[x][y]!=scolor) return;
        image[x][y] = 65536;
        dfs(image,x+1,y,scolor,newColor);
        dfs(image,x-1,y,scolor,newColor);
        dfs(image,x,y+1,scolor,newColor);
        dfs(image,x,y-1,scolor,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        dfs(image,sr,sc,image[sr][sc],newColor);
        for(int i = 0;i<image.size();i++){
            for(int j = 0;j<image[0].size();j++){
                if(image[i][j]==65536) image[i][j] = newColor;
            }
        }
        return image;
    }
};
