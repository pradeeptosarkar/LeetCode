class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size(), rep = 0; //rep->duplicates
        
        for(int i=0;i<m;i++) 
            for(int j=0;j<n;j++) 
                    if(grid[i][j]==1) 
                    {
                        ans++;
                        if(i!=0 && grid[i-1][j]==1) 
                            rep++;
                        if(j!=0 && grid[i][j-1]==1) 
                            rep++;
                        if(i!=m-1 && grid[i+1][j]==1)
                            rep++;
                        if(j!=n-1 && grid[i][j+1]==1)
                            rep++;
                    }
        
        return (4 * ans) - rep;
    }
};