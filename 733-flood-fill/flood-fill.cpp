class Solution {
public:
    void helper(vector<vector<int>>& image,int i,int j,int originalColor,int color){
        if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]!=originalColor){
            return;
        }
        image[i][j]=color;
        helper(image,i+1,j,originalColor,color);
        helper(image,i-1,j,originalColor,color);
        helper(image,i,j+1,originalColor,color);
        helper(image,i,j-1,originalColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color){
            return image;
        }
        helper(image,sr,sc,originalColor,color);
        return image;
    }
};