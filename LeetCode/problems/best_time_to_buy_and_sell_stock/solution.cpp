class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int ans=0, mini=INT_MAX;
        
        for(int i:prices)
        {  
            ans=max(ans,i-mini);
            mini=min(i,mini);
        }
        return ans;
        
    }
};