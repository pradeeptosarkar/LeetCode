class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> dp(n,1), hash(n);
        
        int maxi=1;
        int lastIndex=0;
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
            
            for(int prev=0;prev<i;prev++)
            {
                if(nums[i]%nums[prev]==0 and 1+dp[prev]>dp[i])
                {
                    dp[i]=dp[prev]+1;
                    hash[i]=prev;
                }
            }
            
            if(dp[i]>maxi)
            {
                maxi=dp[i];
                lastIndex=i;
            }
        }
        
        vector<int> ans;
        ans.push_back(nums[lastIndex]);
        
        while(hash[lastIndex]!=lastIndex)
        {
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};