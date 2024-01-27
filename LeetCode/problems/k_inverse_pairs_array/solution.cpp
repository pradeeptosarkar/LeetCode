class Solution {
public:
    int kInversePairs(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                
                else
                {
                    for(int p=0;p<=min(j,i-1);p++)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-p])%1000000007;
                }
            }
        }
        
        return dp[n][k];
    }
};