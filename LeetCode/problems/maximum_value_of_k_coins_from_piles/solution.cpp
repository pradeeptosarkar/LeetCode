class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n=piles.size();
        
        vector dp(n+1, vector<int>(k+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                int currSum=0;
                
                for(int currCoins=0; currCoins<=min((int)piles[i-1].size(), j); currCoins++)
                {
                    if(currCoins>0)
                        currSum+=piles[i-1][currCoins-1];
                    
                    dp[i][j]=max(dp[i][j], dp[i-1][j-currCoins]+currSum);
                }
            }
        }
        return dp[n][k];
    }
};