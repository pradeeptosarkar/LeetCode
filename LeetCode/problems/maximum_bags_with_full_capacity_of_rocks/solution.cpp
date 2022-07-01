class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) 
    {
        int n=capacity.size();
        
        for(int i=0;i<n;i++)
            capacity[i]-=rocks[i];
        sort(capacity.begin(), capacity.end());
        
        int i=0;
        
        for(i;i<n;i++)
        {
            if(additionalRocks>=capacity[i])
                additionalRocks-=capacity[i];
            else
                break;
        }
        return i;
        
    }
};