class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        
        if(n>1)
        {
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    int a,b,c;
                    a=(j==0?10000:matrix[i-1][j-1]);
                    b=matrix[i-1][j];
                    c=(j==n-1?10000:matrix[i-1][j+1]);
                    matrix[i][j]+=min(a,min(b,c));
                }
            }
        }
        
        int ans=INT_MAX;
        
        for(auto i:matrix[n-1])
            ans=min(ans,i);
        
        return ans;
    }
};