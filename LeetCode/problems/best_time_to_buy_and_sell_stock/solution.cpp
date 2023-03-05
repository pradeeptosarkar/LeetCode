class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minTillNow=INT_MAX;
        int ans=0;
        
        for(auto i:prices)
        {
            if(i<minTillNow)
                minTillNow=i;
            if(i-minTillNow>ans)
                ans=i-minTillNow;
        }
        return ans;
    }
};