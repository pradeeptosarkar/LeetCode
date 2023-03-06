class Solution {
public:
    typedef long long int64;
    const int MOD = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) 
    {
        int n = grid.size();
        int m = grid[0].size();
        int64 dp[n][m][k];
        
        memset(dp, 0LL, sizeof(dp));
        dp[0][0][grid[0][0] % k] = 1;
        int rowSum = grid[0][0];
        
        for(int j = 1; j < m; j++) 
        {
            rowSum += grid[0][j];
            dp[0][j][rowSum % k] = (dp[0][j - 1][(rowSum - grid[0][j] + k) % k]) % MOD ;
        }
        
        int colSum = grid[0][0];
        
        for(int i = 1; i < n; i++) 
        {
            colSum += grid[i][0];
            dp[i][0][colSum % k] = (dp[i - 1][0][(colSum - grid[i][0] + k) % k]) % MOD;
        }
        
        for(int i = 1; i < n; i++) 
        {
            for(int j = 1; j < m; j++) 
            {
                for(int x = 0; x < k; x++) 
                {
                    int rem = (k + ((x - grid[i][j]) % k)) % k;
                    dp[i][j][x] = dp[i - 1][j][rem] + dp[i][j - 1][rem];
                    dp[i][j][x] %= MOD;
                }
            }
        }
        return dp[n - 1][m - 1][0] % MOD;
    }
};