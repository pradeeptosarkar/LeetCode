class Solution {
public:
    int dp[101][101];
    
    int Solve(int i,int j,vector<vector<int>>& grid){
        
        if(i>=0 && j>=0 && grid[i][j]==1) return 0;
        
        if(i==0 && j==0) return 1;
        
        if(i<0 || j<0) return 0;
        
        if(dp[i][j] !=-1) return dp[i][j]; 
        
         int left=Solve(i-1,j,grid);
         int right=Solve(i,j-1,grid);
        
        return dp[i][j]=left+right;
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=Solve(n-1,m-1,grid);
        return ans;
        
    }
};