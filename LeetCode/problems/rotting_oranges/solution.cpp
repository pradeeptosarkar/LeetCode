class Solution {
bool mod(vector<vector<int> > &grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>= grid[0].size())
            return false;
        //cout<<i<<" "<<j<<endl;
        if(grid[i][j]==1)
        {
            grid[i][j]=2;
            return true;
        }
        return false;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0; 
        queue<pair<int,int>> q; 
        //fill the queue with rotten oranges  
        for(int i=0; i<grid.size(); i++)
            for(int j =0; j<grid[0].size(); ++j)
            {
                if(grid[i][j]==2)
                {
                    q.push(make_pair(i,j));
                }
            }
        //cout<<q.size()<<endl;
        while(!q.empty())
        {
            int n = q.size();
            for(int l=0; l<n; l++)
            {
                pair<int,int> it = q.front(); 
                int i = it.first;
                int j  = it.second;
                //cout<<i<<" "<<j<<endl;
                q.pop();
                if(mod(grid,i+1,j))
                    q.push(make_pair(i+1,j));
                if(mod(grid,i-1,j))
                    q.push(make_pair(i-1,j));
                if(mod(grid,i,j+1))
                    q.push(make_pair(i,j+1));
                if(mod(grid,i,j-1))
                    q.push(make_pair(i,j-1));
                
            }
            //cout<<q.size()<<endl;
            if(!q.empty())
                ans++;
            
        }
        //check if any cell still has fresh orange
        for(int i=0; i<grid.size(); ++i)
            for(int j=0; j<grid[0].size(); ++j)
            {
                if(grid[i][j]==1)
                    return -1; 
            }
        return ans; 
    }
};