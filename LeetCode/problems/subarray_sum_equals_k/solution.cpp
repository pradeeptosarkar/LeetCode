class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        if(nums.size()==0)
            return 0;
        
        map<int,int> mp;
        int curr=0;
        int ans=0;
        
        for(int i=0;i<nums.size();i++)
        {
            curr+=nums[i];
            
            if(curr==k)
                ans++;
            if(mp.find(curr-k)!=mp.end())
                ans+=mp[curr-k];
            
            mp[curr]++;
        }
        return ans;
        
    }
};