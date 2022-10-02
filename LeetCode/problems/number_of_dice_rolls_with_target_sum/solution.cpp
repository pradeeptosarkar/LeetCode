class Solution {
public:
    
    const long mod = 1000000007;
    
    int solve(int i, int n, int k, int t, vector<vector<int>>& dp)
    {
        if(i==n)
        {
            if(!t)
                return 1;
            return 0;
        }
        
        if(dp[i][t]!=-1)
            return dp[i][t];
        
        long long temp=0;
        
        for(int j=1;j<=k;j++)
            if(t>=j)
                temp+=solve(i+1, n, k, t-j, dp)%mod;
        
        return dp[i][t]=temp%mod;
    }
    
    int numRollsToTarget(int n, int k, int t) 
    { 
        vector<vector<int>> dp(n, vector<int>(t+1, -1));
        return solve(0,n,k,t,dp)%mod;
    }
};