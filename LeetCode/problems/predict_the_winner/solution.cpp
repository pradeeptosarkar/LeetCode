class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        int n=nums.size();
        int dp[n];
        
        for(int i=0;i<n;i++)
            dp[i]=nums[i];
        
        for(int diff=1;diff<n;diff++)
        {
            for(int left=0;left<n-diff;left++)
            {
                int right=left+diff;
                dp[left]=max(nums[left]-dp[left+1], nums[right]-dp[left]);
            }
        }
        
        return dp[0]>=0;
    }
};