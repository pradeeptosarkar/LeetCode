class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n + 2, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            int val= 0;
            for (int j = i + 1; j < n; j++) {
                int prof = (prices[j] - prices[i]) + dp[j + 2];
                val = max(val, prof);
            }
            dp[i] = max(val, dp[i + 1]);
        }
        
        return dp[0];
    }
};