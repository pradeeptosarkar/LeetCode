class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) 
    {
        int ans=0;
        sort(costs.begin(), costs.end());
        
        if(coins<costs[0])
            return 0;
        
        for(auto i:costs)
        {
            if(coins<i)
                return ans;
            
            ans++, coins-=i;            
        }
        
        return ans;
    }
};