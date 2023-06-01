class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini=prices[0], profit=0;
        
        for(int i:prices)
        {
            int cost=i-mini;
            profit=max(profit, cost);
            mini=min(mini, i);
        }
        return profit;
    }
};