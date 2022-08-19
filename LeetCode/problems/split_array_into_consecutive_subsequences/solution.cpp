class Solution {
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int,int> mp,end;
        
        for(int i:nums)
            mp[i]++;
        
        for(int i:nums)
        {
            if(mp[i]==0)
                continue;
            
            mp[i]--;
            
            if(end[i-1]>0)
            {
                end[i-1]--;
                end[i]++;
            }
            
            else if(mp[i+1]>0 and mp[i+2]>0)
            {
                mp[i+1]--;
                mp[i+2]--;
                end[i+2]++;
            }
            
            else
                return false;
        }
        
        return true;
    }
};