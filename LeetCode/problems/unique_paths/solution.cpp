class Solution {
public:
    int uniquePaths(int m, int n) {
		// dp[i][j] stores paths at i, j position
        vector<vector<int>> dp(m, vector<int>(n, -1));
		// we will always have 1 path for the target position
        dp[m-1][n-1] = 1;
        return helper(0, 0, m, n, dp);
    }
private:
     int helper(int i, int j, int m, int n, vector<vector<int>>& dp)
    {
        // return 0 paths if i or j out of bounds
        if(i>=m || j>=n)
            return 0;
        //if ans already known then just return it
        if(dp[i][j]!=-1)
            return dp[i][j];
        //else paths will be sum of paths from one down position and one right position
        return dp[i][j] = helper(i, j+1, m ,n, dp) + helper(i+1, j, m ,n, dp);
        
    }
};