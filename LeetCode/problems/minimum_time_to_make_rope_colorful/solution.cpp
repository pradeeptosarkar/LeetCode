class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) 
    {
        int ans=0, total=0, tempMax=0, i=0, cost=0;
        
        for(i;i<colors.size();i++)
        {
            char temp=colors[i];
            tempMax=0;
            
            while(temp==colors[i])
            {
                total+=neededTime[i];
                tempMax=max(tempMax,neededTime[i]);
                i++;
            }
            
            i--;
            cost+=tempMax;
        }
        
        return total-cost;
    }
};