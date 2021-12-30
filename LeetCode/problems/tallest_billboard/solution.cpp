class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> dp; 
        dp[0] = 0; 
        for (auto& x : rods) {
            unordered_map<int, int> temp = dp; 
            for (auto& [k, v] : temp) {
                dp[k+x] = max(dp[k+x], v); 
                if (x <= k) dp[k-x] = max(dp[k-x], v+x); 
                else dp[x-k] = max(dp[x-k], v+k); 
            }
        }
        return dp[0]; 
    }
};