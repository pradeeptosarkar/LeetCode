class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        if(amount==0 or coins.size()==0)
            return 0;
        
        vector<int> dp(amount+1, amount+2);
        
        dp[0]=0;
        
        for(int i=0;i<coins.size();i++)
        {
            if(coins[i]<=amount)// no use iterating over coins having denomination higher than amount
            {
                for(int j=coins[i];j<=amount;j++)
                {
                    dp[j]=min(dp[j], dp[j-coins[i]]+1);
                }
            }
        }
        
        return dp[amount]==amount+2?-1:dp[amount];
    }
};