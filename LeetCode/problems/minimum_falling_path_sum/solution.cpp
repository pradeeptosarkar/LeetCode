class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int ans=INT_MAX;
        
        int n=matrix.size();
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    matrix[i][j]+=min(matrix[i-1][j], matrix[i-1][j+1]);
                else if(j==n-1)
                    matrix[i][j]+=min(matrix[i-1][j-1], matrix[i-1][j]);
                else
                    matrix[i][j]+=min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1]));
            }
        }
        
        for(auto i:matrix[n-1])
            ans=min(ans,i);
        
        return ans;
    }
};