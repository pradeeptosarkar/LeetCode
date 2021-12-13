class Solution 
{
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int>dp(cost.size()+2,INT_MAX ); 
        dp[0]=dp[1]=0;
        int n=cost.size();
        for (int i=0;i<n;++i) 
        { 
            dp[i+1]=min(cost[i]+dp[i],dp[i+1]); 
            dp[i+2]=min(cost[i]+dp[i],dp[i+2]);
        } 
        return dp[n]; 
    }
};