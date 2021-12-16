class Solution {
    public:
int f(vector<int>&nums,vector<vector<int>>&dp)
    {
        int n=nums.size();
        for(int k=1;k<n-2;k++)
        {
            for(int j=1;j<n-k-1;j++)
            {
                for(int i=j+1;i<j+k;i++)
                {
                    dp[j][j+k]=max(dp[j][j+k],dp[j][i-1]+dp[i+1][j+k]+nums[j-1]*nums[j+k+1]*nums[i]);
                }
                dp[j][j+k]=max(dp[j][j+k],nums[j]*nums[j-1]*nums[j+k+1]+dp[j+1][j+k]);
                dp[j][j+k]=max(dp[j][j+k],nums[j+k]*nums[j-1]*nums[j+k+1]+dp[j][j+k-1]);
            }
        }
        return dp[1][n-2];
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()));
        for(int i=1;i<nums.size()-1;i++)
            dp[i][i]=nums[i]*nums[i+1]*nums[i-1];
        return f(nums,dp);
    }
};