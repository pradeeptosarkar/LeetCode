class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit=0, Min=INT_MAX;      
        for(int i=0;i<prices.size();i++)
        {
            profit=max(profit,prices[i]-Min);
            Min=min(Min,prices[i]);
        }
    
    return profit;  
    }
};