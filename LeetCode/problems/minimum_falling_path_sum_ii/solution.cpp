class Solution {
public:
    
    int minElem(vector<vector<int>> &grid, int row, int i, int n)
    {
        int ans=INT_MAX;
        
        if(i==0)
            ans=*min_element(grid[row-1].begin()+1,grid[row-1].end());
        else if(i==n-1)
            ans=*min_element(grid[row-1].begin(),grid[row-1].begin()+n-2);
        else
            ans=min((*min_element(grid[row-1].begin(),grid[row-1].begin()+i-1)),(*min_element(grid[row-1].begin()+i+1,grid[row-1].end())));
        
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        
        if(n>1)
        {
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int temp=INT_MAX;
                    
                    for(int k=0;k<n;k++)
                    {
                        if(j==k)
                            continue;
                        temp=min(temp,grid[i][j]+grid[i-1][k]);
                    }
                    
                    grid[i][j]=temp;
                }
            }
        }
        
        int ans=INT_MAX;
        
        for(auto i:grid[n-1])
            ans=min(ans,i);
        
        return ans;
    }
};