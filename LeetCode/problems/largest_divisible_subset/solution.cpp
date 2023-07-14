class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
            return {nums[0]};
        if(n==0)
            return {};
        
        vector<int> dp(n,1);
        sort(nums.begin(), nums.end());
        int ans=1;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i])
                    dp[i]=1+dp[j];
                    
                ans=max(ans,dp[i]);
            }
        }
        
        int prev=-1;
        vector<int> lis;
        
        for(int i=n-1;i>=0;i--)
        {
            if(dp[i]==ans and (prev==-1 or nums[prev]%nums[i]==0))
            {
                lis.push_back(nums[i]);
                prev=i;
                ans--;
            }
        }
        return lis;
        
    }
};