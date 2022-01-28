class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
     
        int row=grid.size(), col=grid[0].size(), area=0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1)
                    area=max(area,dfsHelper(i,j,grid));
            }
        }
        return area;
    }
    
    int dfsHelper(int i, int j, vector<vector<int>>& grid)
    {
        if(grid[i][j]==0)
            return 0;
        grid[i][j]=0;
        return 1 + (i-1 >= 0 ? dfsHelper(i-1, j, grid) : 0)  + 
            (i + 1 < grid.size() ? dfsHelper(i+1, j, grid) : 0) +
            (j-1 >= 0 ? dfsHelper(i, j-1, grid) : 0) + 
            (j + 1 < grid[0].size() ? dfsHelper(i, j+1, grid) : 0);
    }
};