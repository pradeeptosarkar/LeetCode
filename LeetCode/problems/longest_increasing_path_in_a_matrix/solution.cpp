class Solution {
public:
    int N,M;
    vector<vector<int>>dp; 
    
    int dfs(int x, int y, vector<vector<int>>&matrix)
    {
        if(dp[x][y])
            return dp[x][y];
        
        vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
        int ans=1;
        
        for(int i=0;i<4;i++)
        {
            int X=x+dir[i][0];
            int Y=y+dir[i][1];
            
            if(X<0 || X>=N || Y<0 || Y>=M)
                continue;
            if(matrix[X][Y]<=matrix[x][y])
                continue;
            ans=max(ans, 1+dfs(X,Y,matrix));
        }
        return dp[x][y]=ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        if(matrix.size()==0)
            return 0;
        
        N=matrix.size();
        M=matrix[0].size();
        dp=vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res=0;
        
        for(int i=0;i<matrix.size();i++)
            for(int j=0;j<matrix[0].size();j++)
                res=max(res, dfs(i,j,matrix));
        
        return res;
    }
};