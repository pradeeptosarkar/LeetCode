class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 and j==0)
                    dp[i][j]=grid[i][j];
                
                else
                {
                    int up=0, left=0;
                    
                    i>0 ? up+=dp[i-1][j] : up+=1e9;
                    j>0 ? left+=dp[i][j-1] : left+=1e9;
                    
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        
        return dp[m-1][n-1];
    }
};