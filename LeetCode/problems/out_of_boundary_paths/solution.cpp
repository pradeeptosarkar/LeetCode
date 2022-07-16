class Solution {
public:
    int d[4][2]= {{0, 1}, {1, 0}, {-1, 0}, {0, -1}}; 
    int dp[50][50][51]; 
    int backtrack(int m, int n, int maxMove, int row, int col){
        if (row < 0 or col < 0 or row==m or col==n) return 1;
        if (maxMove==0) return 0;
        if (dp[row][col][maxMove]!=-1) return dp[row][col][maxMove]; 
        int ans=0; 
        for (int k=0; k<4; k++) {
            int dx= row + d[k][0]; 
            int dy= col+ d[k][1]; 
            ans = (ans+ backtrack(m, n, maxMove-1, dx, dy))%1000000007; 
            
        }
        return dp[row][col][maxMove]=ans;
        
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
       memset(dp, -1, sizeof(dp)); 
        return backtrack( m,  n, maxMove, startRow, startColumn)%1000000007; 
    }
};