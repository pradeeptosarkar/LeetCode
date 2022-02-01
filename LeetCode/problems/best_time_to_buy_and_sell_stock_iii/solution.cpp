class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        int ans=0;
        
        if(n==1)
            return 0;
        if(n==2)
            return max(0,prices[1]-prices[0]);
        if(n==3)
            return max(prices[2]-min(prices[1],prices[0]),max(0,prices[1]-prices[0]));
        
        vector<int> dpa(n),dpb(n),dp2(n);
        int mintnow=INT_MAX;
        mintnow=min(mintnow,prices[0]);
        mintnow=min(mintnow,prices[1]);
        dpa[2]=-prices[0]+prices[1]-prices[2];
        dpb[1]=-prices[0]+prices[1];
        dpb[2]=max(-mintnow+prices[2],dpb[1]);
        mintnow=min(mintnow,prices[2]);
        
        for(int i=3;i<n;i++)
        {
            dpa[i]=max(dpa[i-1],dpb[i-1]-prices[i]);
            dpb[i]=max(-mintnow+prices[i],dpb[i-1]);
            dp2[i]=dpa[i-1]+prices[i];
            mintnow=min(mintnow,prices[i]);
        }
        
        ans=max(ans,dpb[1]);
        ans=max(ans,dpb[2]);
        ans=max(ans,dpa[2]);
        
        for(int i=3;i<n;i++)
        {
            ans=max(ans,dpa[i]);
            ans=max(ans,dpb[i]);
            ans=max(ans,dp2[i]);
        }
        
        return ans;
    }
};