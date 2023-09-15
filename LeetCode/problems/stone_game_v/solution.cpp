class Solution {
public:
    
    int dp[501][501];
    
    int solve(vector<int>& stoneValue, vector<int>& preSum, int i, int j)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=0;
        
        for(int k=i;k<j;k++)
        {
            int first = preSum[k] - ((i>0)? preSum[i-1]:0);
            int second = preSum[j]-preSum[k];
            
            if(first==second)
                ans = max(ans, max(first+solve(stoneValue, preSum, i,k), second+solve(stoneValue, preSum,k+1,j)));
            
            else if(first<second)
                ans=max(ans, first+solve(stoneValue, preSum, i,k));
            
            else
                ans=max(ans, second+solve(stoneValue, preSum, k+1,j));
        }
        
        return dp[i][j]=ans;
    }
    
    int stoneGameV(vector<int>& stoneValue) 
    {
        memset(dp, -1, sizeof dp);
        
        int n=stoneValue.size();
        
        vector<int> preSum(n);
        preSum[0]=stoneValue[0];
        
        for(int i=1;i<n;i++)
            preSum[i]=preSum[i-1]+stoneValue[i];
        
        return solve(stoneValue, preSum, 0, n-1);
    }
};