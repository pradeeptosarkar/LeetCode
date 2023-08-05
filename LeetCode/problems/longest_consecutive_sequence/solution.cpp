class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans=1;
        int n=nums.size();
        
        if(n==0)
            return 0;
        
        unordered_set<int> sett;
        
        for(int i:nums)
            sett.insert(i);
        
        for(auto i:sett)
        {
            if(sett.find(i-1)==sett.end())
            {
                int cnt=1;
                int j=i;
                
                while(sett.find(j+1)!=sett.end())
                {
                    cnt+=1;
                    j+=1;
                }
                
                ans=max(ans,cnt);
            }           
        }
        
        return ans;        
    }
};