class Solution {
public:
    
    bool dfs(int i, int j, vector<vector<int>>& grid, int m, int n)
    {
        if(grid[i][j])
            return true;
        
        if(i==0 or j==0 or i==m-1 or j==n-1)
            return false;
        
        grid[i][j]=1;
        
        bool top=dfs(i-1,j,grid,m,n);
        bool down=dfs(i+1,j,grid,m,n);
        bool left=dfs(i,j-1,grid,m,n);
        bool right=dfs(i,j+1,grid,m,n);
        
        return left and right and top and down;
    }
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        
        for(int i=1;i<m-1;i++)
            for(int j=1;j<n-1;j++)
                if(grid[i][j]==0)
                    if(dfs(i,j,grid,m,n))
                        ans++;
        
        return ans;
    }
};