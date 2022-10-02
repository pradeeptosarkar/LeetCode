class Solution {
private:
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
            
        int low=0;
        int high=1e6;
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(check(heights,mid))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;
        
    }
    
    bool check(vector<vector<int>>&heights,int mid)
    {
        int r=heights.size();
        int c=heights[0].size();
        int i,j;
  
        vector<vector<int>>vis(r,vector<int>(c,0));
        vis[0][0]=1;
        queue<pair<int,int>>q;
        q.push({0,0});
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==r-1 and y==c-1)
                return true;
            for(int k=0;k<4;k++)
            {
                int nx=dx[k]+x;
                int ny=dy[k]+y;
                if(nx>=0 and ny>=0 and nx<r and ny<c and !vis[nx][ny])
                {
                    int newDistance=abs(heights[nx][ny]-heights[x][y]);
                    
                    if(newDistance<=mid)
                    {
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    }
                    
                }
            }
        }
        return false;
    }
};