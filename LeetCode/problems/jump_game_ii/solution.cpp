class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
        vector<int> dp(n, INT_MAX-1);
        dp[n - 1] = 0;  
        for(int i = n - 2; i >= 0; i--) 
            for(int j = 1; j <= nums[i]; j++) 
                dp[i] = min(dp[i], 1 + dp[min(n - 1, i + j)]);  
        return dp[0];  
    }
};