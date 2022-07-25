class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        map<vector<int>,int> mp1,mp2;
        int n=grid.size();
        
        for(int i=0;i<n;i++)
            mp1[grid[i]]++;
    
        for(int i=0;i<n;i++)
        {
        
            vector<int>temp;
            
            for(int j=0;j<n;j++)
                temp.push_back(grid[j][i]);
        
            mp2[temp]++;
        }
    
        int ans=0;
    
        for(auto it:mp1)
    
        {
            for(auto itr:mp2)
            {
                if(it.first==itr.first)
                    ans+=(it.second*itr.second);
            }
        }
        return ans;
    }
};