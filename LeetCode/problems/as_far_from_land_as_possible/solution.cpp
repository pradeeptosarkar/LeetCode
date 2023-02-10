class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        queue<pair<pair<int,int>,int>>q;
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1&&vis[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        int drow[]={0,0,1,-1};
        int dcol[]={1,-1,0,0};
        int ans=-1;
        int flag=0;
        
        while(q.size()>0)
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            q.pop();
              ans=max(ans,t);
              for(int i=0;i<4;i++)
              {
                  int nrow=drow[i]+r;
                  int ncol=dcol[i]+c;
                  if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==0&&grid[nrow][ncol]==0)        {           
                      flag=1;
                      q.push({{nrow,ncol},t+1});
                      vis[nrow][ncol]=1;
                  }
              }
        }
        
         if(flag==0)
           return -1;
        
        return ans;
    }
};