class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        dp[0][0]=grid[0][0];
        
        int p=2*(n-1);
        
        for(int k=1;k<=p;k++)
        {
            for(int i=min(n-1,k);i>=0;--i)
            {
                if(k-i>=n)
                    continue;
                
                for(int j=min(n-1,k);j>=0;--j)
                {
                    if(k-j>=n or grid[i][k-i]<0 or grid[j][k-j]<0)
                    {
                        dp[i][j]=-1;
                        continue;
                    }
                    
                    int temp=dp[i][j];
                    
                    if(i>0)
                        temp=max(temp, dp[i-1][j]);
                    if(j>0)
                        temp=max(temp, dp[i][j-1]);
                    if(i>0 and j>0)
                        temp=max(temp, dp[i-1][j-1]);
                    
                    if(temp<0)
                        continue;
                    
                    dp[i][j]=temp+grid[i][k-i];
                    if(i!=j)
                        dp[i][j]+=grid[j][k-j];
                }
            }
        }
        return max(dp[n-1][n-1], 0);
    }
};