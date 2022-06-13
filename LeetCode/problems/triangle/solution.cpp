class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n=triangle.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        ans[0][0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                    ans[i][j]=ans[i-1][j]+triangle[i][j];
                
                else if(j==triangle[i].size()-1)
                    ans[i][j]=ans[i-1][j-1]+triangle[i][j];
                
                else
                    ans[i][j]=min(ans[i-1][j],ans[i-1][j-1])+triangle[i][j];
            }
        }
        int soln=INT_MAX;
        for(int i=0;i<n;i++)
            soln=min(soln,ans[n-1][i]);
        return soln;
        
    }
};