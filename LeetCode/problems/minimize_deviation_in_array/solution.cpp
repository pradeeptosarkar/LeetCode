class Solution {
public:
    int minimumDeviation(vector<int>& nums) 
    {
        set<int> maxi;
        int ans=INT_MAX;
        
        for(auto i: nums)
        {
            if(i%2)
                maxi.insert(i*2);
            else
                maxi.insert(i);
        }
        
        while(true)
        {
            int devi=(*(maxi.rbegin()) - *(maxi.begin()));
            
            ans=min(ans,devi);
            int max_val=*(maxi.rbegin());
            
            if(max_val%2==0)
            {
                maxi.erase(max_val);
                maxi.insert(max_val/2);
            }
            else
                break;
        }
        return ans;      
    }
};