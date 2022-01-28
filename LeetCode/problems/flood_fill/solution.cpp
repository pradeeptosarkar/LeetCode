class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j, int oc, int nc, int m, int n)
    {
        if(i<0 or j<0 or i>=m or j>=n or image[i][j]!=oc)
            return;
        if(image[i][j]==oc)
            image[i][j]=nc;
        
        dfs(image,i+1,j,oc,nc,m,n);
        dfs(image,i,j+1,oc,nc,m,n);
        dfs(image,i-1,j,oc,nc,m,n);
        dfs(image,i,j-1,oc,nc,m,n);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
     
        int m=image.size();
        int n=image[0].size();
        if(image[sr][sc]!=newColor)
            dfs(image,sr,sc,image[sr][sc],newColor,m,n);
        return image;
    }
};