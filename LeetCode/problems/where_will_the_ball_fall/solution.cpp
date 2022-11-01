class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> v(m+1,vector<int> (n+1,-1));

        for(int j=0;j<n;j++)
        {
            v[m][j]=j;
        }
        for(int i=m-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    if((j+1)!=n&&grid[i][j+1]==1)
                        v[i][j]=v[i+1][j+1];
                }
                else
                {
                    if(j-1>=0&&grid[i][j-1]==-1)
                        v[i][j]=v[i+1][j-1];
                }
            }
        }
        vector<int> ans;
        
        for(int j=0;j<n;j++)
            ans.push_back(v[0][j]);
        return ans;
    }
};