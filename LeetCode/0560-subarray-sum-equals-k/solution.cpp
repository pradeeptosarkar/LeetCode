class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int ans=0, preSum=0;
        unordered_map<int,int> mp;
        
        mp[0]=1;
        
        for(int i:nums)
        {
            preSum+=i;
            
            if(mp.find(preSum-k)!=mp.end())
                ans+=mp[preSum-k];
            
            mp[preSum]++;
        }
        
        return ans;
    }
};
