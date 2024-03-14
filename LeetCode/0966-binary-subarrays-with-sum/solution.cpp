class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int ans=0, preSum=0;
        unordered_map<int,int> mp;
        
        mp[0]=1;
        
        for(int i:nums)
        {
            preSum+=i;
            
            if(mp.find(preSum-goal)!=mp.end())
                ans+=mp[preSum-goal];
            
            mp[preSum]++;
        }
        
        return ans;
    }
};
